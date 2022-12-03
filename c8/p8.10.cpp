#include <iostream>
#include <string>
#include <limits>
#include<cmath>

#define I_MAX numeric_limits<double>::max()
#define I_MIN numeric_limits<double>::min()

using namespace std;
namespace fourOp{
    double plus(double a,double b);
    double minus(double a,double b);
    double multiply(double a, double b);
    double divide(double a,double b);
}

struct overFlowError {
    string s="OVERFLOW";
};
struct underFlowError {
    string s="UNDERFLOW";
};

double fourOp::plus(double a, double b)
{
//    bool f0=(a>0 && b>0 && c<0) || (a<0 && b<0 && c>0);//not best
    if((a>0.0 && b > I_MAX - a) || (a < 0.0 && b < -I_MAX - a)){
        throw overFlowError();
    }
    double c = a + b;
    if(a!=0.0 && b!=0.0 && c==0){
        throw underFlowError();
    }
    return c;
}

double fourOp::minus(double a, double b)//c=a-b
{
//    double c = a - b;
//    if(a>0 && b<0 && c<0 || a<0 && b>0 && c>0){
//        throw overFlowError();
//    }else if(){//
//        throw underFlowError();
//    }
//    return c;
    return fourOp::plus(a,-b);//perfect!
}

double fourOp::multiply(double a, double b)
{
    if(fabs(a)>1.0 && b > I_MAX / fabs(a)){//It's the same case when exchange a and b,while avoiding overflow.
        throw overFlowError();
    }
    double c = a * b;
    if(a!=0.0 && b!=0.0 && c==0){
        throw underFlowError();
    }
    return c;
}

double fourOp::divide(double a, double b)//c=a/b
{
    if(fabs(b)<1.0 && fabs(a) > I_MAX * fabs(b)){//overflow is impossible when fabs(b)>1.0.
        throw overFlowError();
    }
    double c = (double)a/b;
    if(a!=0.0 && c==0){//b can't be 0.
        throw underFlowError();
    }
    return c;
}

void calculator(double a,double b){
    //plus
    try{
        double ans = fourOp::plus(a, b);
        cout << "plus: " << ans << endl;
    }catch(overFlowError ofe){
        cout << "PLUS " << ofe.s << endl;
    }catch(underFlowError ufe){
        cout << "PLUS " << ufe.s << endl;
    }
    //minus
    try{
        double ans = fourOp::minus(a, b);
        cout << "minus: " << ans << endl;
    }catch(overFlowError ofe){
        cout << "MINUS " << ofe.s << endl;
    }catch(underFlowError ufe){
        cout << "MINUS " << ufe.s << endl;
    }
    //multiply
    try{
        double ans = fourOp::multiply(a, b);
        cout << "multiply: " << ans << endl;
    }catch(overFlowError ofe){
        cout << "MULTIPLY " << ofe.s << endl;
    }catch(underFlowError ufe){
        cout << "MULTIPLY " << ufe.s << endl;
    }
    //divide
    try{
        double ans = fourOp::divide(a, b);
        cout << "divide: " << ans << endl;
    }catch(overFlowError ofe){
        cout << "DIVIDE " << ofe.s << endl;
    }catch(underFlowError ufe){
        cout << "DIVIDE " << ufe.s << endl;
    }
}

//I don't know if it could be called a bug,
//that if the input is overflow,
//this program can't find the flow error.
//So the legal input is required.
int main()
{
    cout << I_MIN;
    double a,b;
    cout << "a :";
    cin >> a;
    cout << "b :";
    cin >> b;
    calculator(a,b);

    return 0;
}

