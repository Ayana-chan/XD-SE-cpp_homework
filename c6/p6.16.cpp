#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include<cmath>

using namespace std;

namespace digitTran{
    enum baseEnum{d=10,o=8,h=16};
    int getDigit(char c,baseEnum base=baseEnum(d));//turn char into digit.Base is needed to find unexpected char.
    int atoi(string s);
    struct charError{string es="ERROR:UNEXPECTED CHAR";};
}

//Flow error start
//2147483647
#define I_MAX numeric_limits<int>::max()
#define I_MIN numeric_limits<int>::min()

struct overFlowError {
    string s="OVERFLOW";
};
struct underFlowError {
    string s="UNDERFLOW";
};

int _plus(int a, int b)
{
//    bool f0=(a>0 && b>0 && c<0) || (a<0 && b<0 && c>0);//not best
    if((a>0.0 && b > I_MAX - a) || (a < 0.0 && b < -I_MAX - a)){
        throw overFlowError();
    }
    int c = a + b;
    if(a!=0.0 && b!=0.0 && c==0){
        throw underFlowError();
    }
    return c;
}

int _multiply(int a, int b)
{
    if(abs(a)>1.0 && b > I_MAX / abs(a)){//It's the same case when exchange a and b,while avoiding overflow.
        throw overFlowError();
    }
    int c = a * b;
    if(a!=0.0 && b!=0.0 && c==0){
        throw underFlowError();
    }
    return c;
}
//end

int digitTran::getDigit(char c, baseEnum base) {
    if(c>='0' && c<='7')
        return c-'0';
    if(base==baseEnum(o))//unexpected char when 8
        throw digitTran::charError();

    if(c>='8' && c<='9')
        return c-'0';
    if(base==baseEnum(d))//unexpected char when 10
        throw digitTran::charError();

    if(c>='a' && c<='f')
        return c-'a'+10;
    if(c>='A' && c<='F')
        return c-'A'+10;
    throw digitTran::charError();//unexpected char when 16
}

int digitTran::atoi(string s) {
    //cpp character constant notation,like "'a'".
    bool isCharConstant=s[0] == '\'' && s[2] == '\'';
    if(s.length()==3 && isCharConstant) {
        return digitTran::getDigit(s[1]);//get "a",and immediately output.
    }
    //judge negative
    int flag_negative=0;//1 means negative
    if(s[0]=='-'){
        flag_negative=1;
        for(int i=0;i<s.length()-1;i++){
            s[i]=s[i+1];
        }
    }
    //get base
    auto base = baseEnum(d);//default 10
    if(s[0] == '0') {
        base = baseEnum(o);
        if(s.length()>1 && (s[1] == 'x' || s[1]=='X')) {
            base = baseEnum(h);
        }
    }
    //calculate ans
    int ans = 0;
    int i=0;
    if(base==baseEnum(h)){//ignore "0x".It's unnecessary to do it when base=8.
        i=2;
    }
    for( ; i<s.length()-flag_negative ; i++){
//        ans *= base;
//        ans += digitTran::getDigit(s[i],base);
        ans=_multiply(ans,base);
        ans=_plus(ans,digitTran::getDigit(s[i],base));
    }
    if(flag_negative){
        ans=-ans;
    }
    return ans;
}

int main()
{
    while(true) {
        string s;
        cin >> s;
        try {
            int ans = digitTran::atoi(s);
            cout << ans << endl;
        } catch (digitTran::charError ce) {
            cout << ce.es << endl;
        } catch (overFlowError fe) {
            cout << fe.s << endl;
        } catch (underFlowError fe) {
            cout << fe.s << endl;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
