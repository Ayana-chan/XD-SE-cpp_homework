#include <iostream>

#define B_MAX_SIZE 500

using namespace std;



namespace stringTran{
    char* itoa(int i, char b[]);
}

char* stringTran::itoa(int i, char b[])
{
    int flag_negative=0;
    //when negative
    if(i==-2147483648){
        return "-2147483648";
    }
    if(i<0){
        b[0]='-';
        flag_negative=1;
        i=-i;
    }

    int temp[B_MAX_SIZE]={0};//fliped i's array
    int p=0;//pointer
    //divide
    while(i!=0){
        temp[p++]= i % 10;
        i/=10;
    }
    //flip
    int p2=0;
    for(; p > 0; p--){
        b[flag_negative + p - 1]= '0' + temp[p2++];
    }

    return b;
}

int main()
{
    while(true) {
        int i;
        cin >> i;
        char b[B_MAX_SIZE] = {0};

        cout << stringTran::itoa(i, b) << endl << endl;
    }

    system("pause");
    return 0;
}
