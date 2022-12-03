#include <iostream>

using namespace std;

class Vec4
{
private:
    float vS[4];
public:


    Vec4();//set default 0
    Vec4(const float& i0, const float& i2, const float& i3, const float& i4);
    Vec4(const Vec4& vv);

    float& operator[](const int index);//could assign directly

    Vec4 operator-() const;
    //+ depends on += , for less temp object.
    Vec4 operator+(const Vec4& sec) const;
    Vec4 operator-(const Vec4& sec) const;
    Vec4 operator*(const Vec4& sec) const;
    Vec4 operator/(const Vec4& sec) const;
    Vec4& operator+=(const Vec4& sec);
    Vec4& operator-=(const Vec4& sec);
    Vec4& operator*=(const Vec4& sec);
    Vec4& operator/=(const Vec4& sec);

    Vec4 operator+(const float sec) const;
    Vec4 operator-(const float sec) const;
    Vec4 operator*(const float sec) const;
    Vec4 operator/(const float sec) const;
    Vec4& operator+=(const float sec);
    Vec4& operator-=(const float sec);
    Vec4& operator*=(const float sec);
    Vec4& operator/=(const float sec);

    friend Vec4 operator+(const float f, const Vec4& v);
    friend Vec4 operator-(const float f, const Vec4& v);
    friend Vec4 operator*(const float f, const Vec4& v);
    friend Vec4 operator/(const float f, const Vec4& v);
    //I don't think "float+=Vec4" really exist.
    //o
    friend std::ostream& operator<<(std::ostream& output, const Vec4& v);
    //error
    class OutOfRangeException {
    public:
        string es="ERROR:INDEX OUT OF RANGE\n";
    };
};//Vec4


Vec4::Vec4(){
    for(int i = 0; i < 4; i++) {
        vS[i] = 0.0f;
    }
}

Vec4::Vec4(const float& i0, const float& i1, const float& i2, const float& i3) {
    vS[0]=i0;
    vS[1]=i1;
    vS[2]=i2;
    vS[3]=i3;
}

Vec4::Vec4(const Vec4& vv){
    for(int i = 0; i < 4; i++) {
        vS[i] = vv.vS[i];
    }
}

//
float& Vec4::operator[](const int index){
    if(index < 0 || index > 3)
        throw OutOfRangeException();
    return vS[index];
}

Vec4 Vec4::operator-() const{
    Vec4 ans=*this;
    for(int i=0;i<4;i++){
        ans.vS[i]=-ans.vS[i];
    }
    return ans;
}

//v&v
Vec4 Vec4::operator+(const Vec4& sec) const{
    Vec4 ans = *this;
    ans += sec;
    return ans;
}

Vec4 Vec4::operator-(const Vec4& sec) const{
    Vec4 ans = *this;
    ans -= sec;
    return ans;
}

Vec4 Vec4::operator*(const Vec4& sec) const{
    Vec4 ans = *this;
    ans *= sec;
    return ans;
}

Vec4 Vec4::operator/(const Vec4& sec) const{
    Vec4 ans = *this;
    ans /= sec;
    return ans;
}
//
Vec4& Vec4::operator+=(const Vec4& sec){
    for(int i = 0; i < 4; i++)
        vS[i] += sec.vS[i];
    return *this;
}

Vec4& Vec4::operator-=(const Vec4& sec){
    for(int i = 0; i < 4; i++)
        vS[i] -= sec.vS[i];
    return *this;
}

Vec4& Vec4::operator*=(const Vec4& sec){
    for(int i = 0; i < 4; i++)
        vS[i] *= sec.vS[i];
    return *this;
}

Vec4& Vec4::operator/=(const Vec4& sec){
    for(int i = 0; i < 4; i++)
        vS[i] /= sec.vS[i];
    return *this;
}

//v&f
Vec4 Vec4::operator+(const float sec) const{
    Vec4 ans = *this;
    ans += sec;
    return ans;
}

Vec4 Vec4::operator-(const float sec) const{
    Vec4 ans = *this;
    ans -= sec;
    return ans;
}

Vec4 Vec4::operator*(const float sec) const{
    Vec4 ans = *this;
    ans *= sec;
    return ans;
}

Vec4 Vec4::operator/(const float sec) const{
    Vec4 ans = *this;
    ans /= sec;
    return ans;
}
//
Vec4& Vec4::operator+=(const float sec){
    for(int i = 0; i < 4; i++)
        vS[i] += sec;
    return *this;
}

Vec4& Vec4::operator-=(const float sec){
    for(int i = 0; i < 4; i++)
        vS[i] -= sec;
    return *this;
}

Vec4& Vec4::operator*=(const float sec){
    for(int i = 0; i < 4; i++)
        vS[i] *= sec;
    return *this;
}

Vec4& Vec4::operator/=(const float sec){
    for(int i = 0; i < 4; i++)
        vS[i] /= sec;
    return *this;
}

//f&v
Vec4 operator+(const float f, const Vec4& v){
    return v + f;
}

Vec4 operator-(const float f, const Vec4& v) {
    return -(v - f);
}

Vec4 operator*(const float f, const Vec4& v){
    return v * f;
}

Vec4 operator/(const float f, const Vec4& v){
    Vec4 ans;
    for(int i = 0; i < 4; i++)
        ans[i] = f / v.vS[i];
    return ans;
}

//o
std::ostream& operator<<(std::ostream& out, const Vec4& v) {
    out << '[';
    for (int i = 0; i < 4; i++) {
        out << v.vS[i];
        if (i < 3) {
            out << ',';
        }
    }
    out << ']';
    return out;
}

int main() {
    try {
        Vec4 v1 = *new Vec4(0.2, 1.1, 3.1, 6.7);
        cout << "v1 = " << v1 << endl;

        Vec4 v2 = *new Vec4();
        v2[0] = 10.02f;
        v2[1] = 20.03f;
        v2[2] = 10.04f;
        v2[3] = 30.06f;
        cout << "v2 = " << v2 << endl;

        Vec4 v3 = *new Vec4(v1);
        cout << "v3 = " << v3 << endl;

        float f = 300.003f;
        cout << "f = " << f << endl;
        cout << endl;

        cout << "v1 + v2" << " = " << v1 + v2 << endl;
        cout << "v1 - v2" << " = " << v1 - v2 << endl;
        cout << "v1 * v2" << " = " << v1 * v2 << endl;
        cout << "v1 / v2" << " = " << v1 / v2 << endl;
        cout << endl;

        cout << "v1 + f" << " = " << v1 + f << endl;
        cout << "v1 - f" << " = " << v1 - f << endl;
        cout << "v1 * f" << " = " << v1 * f << endl;
        cout << "v1 / f" << " = " << v1 / f << endl;
        cout << endl;

        cout << "f + v1" << " = " << f + v1 << endl;
        cout << "f + v1" << " = " << f - v1 << endl;
        cout << "f + v1" << " = " << f * v1 << endl;
        cout << "f + v1" << " = " << f / v1 << endl;
        cout << endl;

        v1 += v2;
        cout << "v1 += v2 , then v1=" << v1 << endl;
        v3 *= v2;
        cout << "v3 *= v2 , then v3=" << v3 << endl;
        cout << endl;

        cout << "v1[1]-v2[1]=" << v1[1] - v2[1] << endl;

        Vec4 vt;//default
        cout<<vt<<endl;

        v1[5];
    } catch (Vec4::OutOfRangeException e) {
        cerr << e.es;
    }

    system("pause");
    return 0;
}
