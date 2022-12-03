#include <iostream>

struct PureIdeologyException
{
    int content;
    PureIdeologyException(int c){
        content = c;
    }
};

void throwEx()
{
    throw PureIdeologyException(114514);
}

void catchEx()
{
    try{
        throwEx();
    }catch(PureIdeologyException pe) {
        std::cout << "ExGET! :" << pe.content;
    }
}

int main()
{
    catchEx();

    return 0;
}
