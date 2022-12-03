#include <iostream>
#include <cstring>

using std::istream;//necessary for IO
using std::ostream;

class String
{
private:
    struct Srep;//representation
    Srep* rep;

public:
    class Cref;//reference to char
    String();
    String(const char*);
    String(const String&);
    String& operator=(const char*);
    String& operator=(const String&);
    ~String();

    String& operator+=(const String& x);
    String& operator+=(const char* x);
    String operator+(const String& x);
    String operator+(const char* x);

    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);

    friend bool operator==(const String& x, const char* s);
    friend bool operator==(const String& x, const String& y);
    friend bool operator!=(const String& x, const char* s);
    friend bool operator!=(const String& x, const String& y);

    void check(int i) const;//range check
    char read(int i);
    void write(int i, char c);
    //get certain char
    Cref operator[](int i);//tran to Cref as a char-plus
    //error
    class OutOfRangeException {};
    //extra function
    //get sz
    int size() const;
    //get C-string
    const char* c_str();
    //substring
    String operator()(int start, int n) const;
};

struct String::Srep
{
    char* s;//pointer to elements
    int sz;//number of characters
    int n;//reference count

    Srep(int nsz, const char* p)//nsz == new string size
    {
        n = 1;
        sz = nsz;
        s = new char[sz+1];//add space for terminator
        strcpy(s,p);
    }

    ~Srep() { delete[] s; }

    Srep* get_own_copy()//clone if necessary //only after write
    {
        if(n==1) return this;
        n--;
        return new Srep(sz, s);
    }

    void assign(int nsz, const char* p)
    {
        if(sz != nsz) {//recreate when size not fit
            delete[] s;
            sz = nsz;
            s = new char[sz+1];
        }
        strcpy(s,p);
    }

private://prevent copying
    Srep(const Srep&);
    Srep& operator=(const Srep&);
};

class String::Cref{//reference to s[i] ,saving a certain char
    friend class String;
    String& s;
    int i;
    Cref(String& ss, int ii) : s(ss), i(ii) {}
public:
    //to be considered as char
    operator char() { s.check(i); return s.read(i); }
    void operator=(char c) { s.write(i, c); }
};

//constructor
String::String()//the empty string is the default value
{
    rep = new Srep(0, "");
}

String::String(const String& s)//copy constructor
{
    s.rep->n++;
    rep = s.rep;//share representation //need no additional space to save rep[].
}

String::String(const char* s)
{
    rep = new Srep(strlen(s), s);
}

String& String::operator=(const String& s)//copy assignment
{
    s.rep->n++;//protects against "st = st" //If "st = st" , n+=1 then n-=1.
    if(--(rep->n) == 0) delete rep;//self is actually deleted after '='
    rep = s.rep;//share representation
    return *this;
}

String& String::operator=(const char* s)
{
    if(rep->n == 1) {
        rep->assign(strlen(s), s);//recycle Srep , need not to new.
    }
    else
    {
        rep->n--;
        rep = new Srep(strlen(s), s);//use new Srep
    }
    return *this;
}

String::~String()
{
    if(--(rep->n) == 0) delete rep;//reduce n when killed.Delete data when no one need it.
}


String& String::operator+=(const String& x)
{
    return *this += x.rep->s;//use s&c
}

String& String::operator+=(const char* x)
{
    int sz = rep->sz+strlen(x);
    char* s = new char[sz+1];
    strcpy(s, rep->s);
    strcat(s, x);
    rep->assign(sz, s);
    delete s;
    return *this;
}

String String::operator+(const String& x){
    String ans=*this;
    ans+=x;
    return ans;
}

String String::operator+(const char* x){
    String ans=*this;
    ans+=x;
    return ans;
}

//IO
ostream& operator<<(ostream& output, const String& x)
{
    output << x.rep->s;//output by char*
    return output;
}

istream& operator>>(istream& input, String& x) {
    const int ATOM_INPUT_SIZE = 16;

    int max_size = ATOM_INPUT_SIZE;
    char *str = new char[max_size + 1];
    int pos = 0;//which index to input
    char ch;

    while (input && input.get(ch) && !isspace(ch))//won't read space but eat it
    {
        str[pos++] = ch;
        if (pos == max_size)//if may no place for '\0'
        {
            max_size += ATOM_INPUT_SIZE;//modify this formula to change input size rule
            char *newS = new char[max_size + 1];//need a bigger char[]
            str[pos] = 0;//end the char* for strcpy()
            strcpy(newS, str);
            delete[] str;
            str = newS;
        }
    }
    str[pos] = 0;//end 0 at max pos

    x = String(str);
    delete[] str;
    return input;
}

bool operator==(const String& x, const char* s) { return strcmp(x.rep->s, s)==0; }
bool operator==(const String& x, const String& y) { return strcmp(x.rep->s, y.rep->s)==0; }
bool operator!=(const String& x, const char* s) { return strcmp(x.rep->s, s)!=0; }
bool operator!=(const String& x, const String& y) { return strcmp(x.rep->s, y.rep->s)!=0; }

void String::check(int i) const { if(i<0 || i>=rep->sz) throw OutOfRangeException(); }
char String::read(int i) { return rep->s[i]; }
void String::write(int i, char c) { rep = rep->get_own_copy(); rep->s[i] = c; }

String::Cref String::operator[](int i) { check(i); return Cref(*this, i); }

int String::size() const {
    return rep->sz;
}

const char* String::c_str()
{
    return rep->s;
}

String String::operator()(int start, int n) const
{
    check(start);
    check(start + n - 1);
    char* subs = new char[n + 1];
    strncpy(subs, rep->s + start, n);
    subs[n] = 0;
    return subs;
}

//test
using std::cin;
using std::cout;
using std::endl;

String f(String a, String b)
{
    a[2] = 'x';
    char c = b[3];
    cout << "in f: " << a << ' ' << b << ' ' << c << '\n';
    return b;
}

int main() {
    try {
        String x, y;
        //IO
        cout << "Please enter two strings\n";
        cin >> x >> y;
        cout << "input: " << x << ' ' << y << endl;

        String z = x;
        y = f(x, y);
        if (x != z) cout << "x corrupted!\n";
        x[0] = '!';
        if (x == z) cout << "write failed!\n";

        z+=x;
        cout<< "z+=x; then z+y = " <<z+y<<endl;

        cout << "exit:" << x << ' ' << y << ' ' << z << endl;

        //substring
        cout << "substring: \"" << x << "\"" << "(1,2) = " << x(1, 2) << endl;
        //C-string
        cout << "C-string: \"" << x << "\"" << ".c_str() = " << x.c_str() << endl;
        //size
        cout << "size: \"" << x << "\"" << ".size() = " << x.size() << endl;
    }catch (String::OutOfRangeException){
        cout<<"ERROR : Out Of Range\n";
    }

    system("pause");
}