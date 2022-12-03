#include <iostream>

using namespace std;

struct X {
    int i;
    X(int ii) {
        i = ii;
    }
    X operator+(int a) {
        return X(i + a);
    }
    friend ostream & operator<<(ostream &out,const X &x){
        out << x.i;
        return out;
    }
};

struct Y {
    int i;
    Y(X x) {
        i = x.i;
    }
    Y operator+(X x) {
        return Y(i + x.i);
    }
    operator int() {
        return i;
    }
    friend ostream & operator<<(ostream &out,const Y &y){
        out << y.i;
        return out;
    }
};

X operator*(X x,Y y) {
    return {x.i*y.i};
}
int f(X x) {
    return x.i;
}

X x = 1; 
Y y = x;
int i = 2;

int main() {
    cout << i + 10 << endl; // int operator+(int)
    cout << int(y) + 10 << endl; // (int)y+10 ? y+X(10) ?
    cout << int(y) + 10 * int(y) << endl; // y+(10*(int)y) ? y+(X(10)*y) ?
    cout << x + y + i << endl; // Y int() , X operator+()  , X operator+(int)
    cout << x * x + i << endl; // Y(X) , X operator*(X,Y) , X operator+(int)
    cout << f(7) << endl; // X(int) , f(X)
    cout << f((int) y) << endl; //No X(Y).
    cout << y + y << endl; // Y int() , Y int() , int operator+(int).Because No X(Y).
    cout << 106 + y << endl; // Y int() , int operator+(int)
}
