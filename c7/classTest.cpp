#include <iostream>

using namespace std;

class Fat{
public:
    int a;
    virtual void getType(){
        cout << "f\n";
    }
    int getnum(int *a){
        return *a;
    }
};
class Chi: public Fat{
public:
    void getType(){
        cout << "c\n";
    }
};

void ff(Fat fat){
    cout<< "father";
}
void ff(Chi chi){
    cout<< "child";
}

int main(){
    Fat fat;
    Chi chi;
    Chi* pc;
    Fat tfat=chi;
    Fat* pf=&chi;
    Fat** ppf=&pf;
    Fat& yf=chi;
//    if(typeid(**ppf)== typeid(Chi)){
//        cout << "1\n";
//    }
//    chi.getType();
//    tfat.getType();
//    pf->getType();
//
//    int a=24243;
//    cout << fat.getnum(&a);

    ff(chi);

    return 0;
}
