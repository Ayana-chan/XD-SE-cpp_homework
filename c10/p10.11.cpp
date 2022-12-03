#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Expr{
private:
    class TNode{
    public:
        string str;
        TNode* lchild;
        TNode* rchild;
        TNode(string nextFormula);
    };
    TNode* root;

    string formula;//a+b
    string bracketForm;//(a+(b*c))
    string suffixForm;//ab*
    string compilationForm;//ADD AX,BX

    int getAns(TNode* node);//calculate

    void tranBracket();
    void tranSuffix();
    void tranCompilation();

    string midOrder_bra(TNode* node);
    string postOrder_suf(TNode* node);
    char postOrder_com(TNode* node,map<char,bool> &regMap);
public:
    Expr(const char *);
    int eval();
    void print();
};

Expr::Expr(const char * exx) {
    formula=exx;
    root=new TNode(formula);//build a tree;
}

int Expr::eval() {
    return getAns(root);
}

void Expr::print() {
    cout << "originalForm: " << formula << endl;

    tranBracket();
    cout << "bracketForm: " << bracketForm << endl;

    tranSuffix();
    cout << "suffixForm: " << suffixForm << endl;

    tranCompilation();
    cout << "compilationForm: \n" << compilationForm << endl;
}

Expr::TNode::TNode(string nextFormula) {
    bool isAllDigit=true;
    int i=nextFormula.length()-1;//the place of operator
    for(;i>=0;i--){
        if(nextFormula[i]>='0' && nextFormula[i]<='9'){
            continue;
        }
        //have operator
        isAllDigit= false;
        if(nextFormula[i]=='*' || nextFormula[i]=='/'){//divide "1+2-3" by '-'
            for(int j=i-1; j>=0 ;j--){
                if(nextFormula[j]=='+' || nextFormula[j]=='-'){
                    i=j;
                    break;
                }
            }
        }
        break;
    }
    if(isAllDigit){
        str=nextFormula;
        lchild= nullptr;
        rchild= nullptr;
    }else{
        str=nextFormula[i];
        lchild=new Expr::TNode(nextFormula.substr(0,i));
        rchild=new Expr::TNode(nextFormula.substr(i+1));
    }
}

int Expr::getAns(TNode *node) {
    if(node->lchild== nullptr && node->lchild== nullptr){//number
        return atoi(node->str.c_str());
    }
    //operator
    switch (*(node->str.c_str())) {
        case '+':
            return getAns(node->lchild) + getAns(node->rchild);
        case '-':
            return getAns(node->lchild) - getAns(node->rchild);
        case '*':
            return getAns(node->lchild) * getAns(node->rchild);
        case '/':
            return getAns(node->lchild) / getAns(node->rchild);
    }
    return 0;//useless
}

void Expr::tranBracket() {
    bracketForm= midOrder_bra(root);
}

void Expr::tranSuffix() {
    suffixForm= postOrder_suf(root);
}

void Expr::tranCompilation() {
    //true means available
    map<char,bool> regMap={{'A', true}, {'B', true}, {'C', true}, {'D', true}};
    postOrder_com(root, regMap);
    compilationForm+="\tHLT\n\t#Ans is in AX.";
}

string Expr::midOrder_bra(TNode* node) {
    if(node->lchild== nullptr && node->rchild== nullptr){
        return node->str;
    }
    return "(" + midOrder_bra(node->lchild) + node->str + midOrder_bra(node->rchild) + ")";
}

string Expr::postOrder_suf(TNode* node) {
    if(node->lchild== nullptr && node->rchild== nullptr){
        return node->str;
    }
    return postOrder_suf(node->lchild) + postOrder_suf(node->rchild) + node->str;
}

char Expr::postOrder_com(TNode* node, map<char,bool> &regMap) {
    if(node->lchild== nullptr && node->rchild== nullptr){
        char reg;//register needed
        //find an available reg
        for(auto &[mreg,bo]:regMap){
            if(bo){
                bo= false;//unavailable
                reg=mreg;
                break;
            }
        }
        compilationForm+= "\tMOV " + string(1, reg) + "X," + node->str + "\n";
        return reg;
    }
    char regL= postOrder_com(node->lchild, regMap);
    char regR= postOrder_com(node->rchild, regMap);
    switch (*(node->str.c_str())) {
        case '+':
           compilationForm+= "\tADD " + string(1, regL) + "X," + string(1, regR) + "X\n";
            break;
        case '-':
            compilationForm+= "\tSUB " + string(1, regL) + "X," + string(1, regR) + "X\n";
            break;
        case '*':
            compilationForm+= "\tMUL " + string(1, regL) + "X," + string(1, regR) + "X\n";
            break;
        case '/':
            compilationForm+= "\tDIV " + string(1, regL) + "X," + string(1, regR) + "X\n";
            break;
    }
    regMap.find(regR)->second= true;//available
    return regL;
}

int main()
{
    const char* f="2+669/223*7-1";
    Expr x=Expr(f);
    cout << "x=" << x.eval() << endl;
    x.print();

    return 0;
}


