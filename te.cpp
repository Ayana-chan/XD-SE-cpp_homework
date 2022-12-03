#include <iostream>
#include <cstring>

using namespace std;

class R {
public:
    R(){cout << "r"<< endl;}
    R(int i){cout << i<< endl;}
};
class A {
public:
    R r;
    A() {
        r=114;
        cout << "c"<< endl;
    }

    ~A() { cout << "d" << endl; }
    friend ostream &operator<<(ostream& out,A a);
};
ostream &operator<<(ostream& out,A a);
ostream &operator<<(ostream& out,A a);
ostream &operator<<(ostream& out,A a){
    cout<<"abc"<<endl;
    return out;
}

int main(){
    A a=A();
    cout<<a;
}


