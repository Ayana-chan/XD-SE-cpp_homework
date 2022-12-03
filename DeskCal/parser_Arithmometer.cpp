#include "parser.h"
#include "error.h"

using namespace Parser_Arithmometer;
using namespace Parser_BasicReader;
using namespace Error;

//flow error
//start
//#include <limits>
//#include<cmath>
//
//#define I_MAX numeric_limits<int>::max()
//#define I_MIN numeric_limits<int>::min()
//
//namespace fourOp{
//    double plus(int a,int b);
//    double minus(int a,int b);
//    double multiply(int a, int b);
//    double divide(int a,int b);
//}
//
//struct overFlowError {
//    string s="OVERFLOW";
//};
//struct underFlowError {
//    string s="UNDERFLOW";
//};
//
//int fourOp::plus(int a, int b)
//{
////    bool f0=(a>0 && b>0 && c<0) || (a<0 && b<0 && c>0);//not best
//    if((a>0.0 && b > I_MAX - a) || (a < 0.0 && b < -I_MAX - a)){
//        throw overFlowError();
//    }
//    int c = a + b;
//    if(a!=0.0 && b!=0.0 && c==0){
//        throw underFlowError();
//    }
//    return c;
//}
//
//int fourOp::minus(int a, int b)//c=a-b
//{
////    double c = a - b;
////    if(a>0 && b<0 && c<0 || a<0 && b>0 && c>0){
////        throw overFlowError();
////    }else if(){//
////        throw underFlowError();
////    }
////    return c;
//    return fourOp::plus(a,-b);//perfect!
//}
//
//int fourOp::multiply(int a, int b)
//{
//    if(fabs(a)>1.0 && b > I_MAX / fabs(a)){//It's the same case when exchange a and b,while avoiding overflow.
//        throw overFlowError();
//    }
//    double c = a * b;
//    if(a!=0.0 && b!=0.0 && c==0){
//        throw underFlowError();
//    }
//    return c;
//}
//
//double fourOp::divide(double a, double b)//c=a/b
//{
//    if(fabs(b)<1.0 && fabs(a) > I_MAX * fabs(b)){//overflow is impossible when fabs(b)>1.0.
//        throw overFlowError();
//    }
//    double c = (double)a/b;
//    if(a!=0.0 && c==0){//b can't be 0.
//        throw underFlowError();
//    }
//    return c;
//}
//end


//These three functions execute each other,so they need statement first.
//Here using namespace is enough.

//handle + -
double Parser_Arithmometer::expr(bool get) {//TIPS:calculation should start by expr(false).
    //'left' is the value of the formula that have been calculated.
    double left = term(get);//get the first (part of formula's) value.
    for (;;) {
        switch (curr_tok) {
            //reason to execute term:
            // if next calculate is * or / , do * or / first.
            case PLUS:
                left += term(true);
                break;
            case MINUS:
                left -= term(true);
                break;
            default:
                return left;//Return the value of the formula that has been calculated (as answer).
        }
    }
}
//handle * /
double Parser_Arithmometer::term(bool get) {
    double left = prim(get);//get value of defined type from prim().
    for (;;) {
        switch (curr_tok) {
            //reason to execute prim:
            // if next calculate is + or - ,
            // instead of do that immediately (which is wrong),
            // we should check the "()".
            case MUL:
                left *= prim(true);
                break;
            case DIV:
                if (double d = prim(true)) {//false only when d=0.
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;//Return the value of the formula that has been calculated
        }
    }
}
//handle primaries
double Parser_Arithmometer::prim(bool get) {
    if (get)
        get_token();//the next value wouldn't be read here,unless the next formula is independent(highest priority).
    switch (curr_tok) {
        case NUMBER: { //floating-point constant
            double v = number_value;
            get_token();
            return v;
        }
        case NAME: {
            double &v = table[string_value];
            if (get_token() == ASSIGN)
                v = expr(true);//Calculate the NAME v's value.
            return v;
        }
        case MINUS: { //unary minus (example:'-' in "-114514")
            return -prim(true);//return negative value
        }
        case LP: { //handle "()"
            double e = expr(true);//calculate the formula in this "()"
            //If formula in "()" have no any error,the next char should be ")" exactly.
            if (curr_tok != RP)
                return error("')' expected");
            get_token();//eat ')'
            return e;
        }
        default:
            return error("primary expected");
    }
}


