#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Tnode{
public:
    string word;//char* can be a ptr of a char array.
    int count;//not requested anything,but I use it to count how much times this word appears.
    Tnode* left;
    Tnode* right;
};

class Tnode_chged : public Tnode{//change the type of 'word'
public:
    char* c_word;//char* is a ptr of a char array.
};

//use binary sorted tree.
//dynamic search
void dsNode(Tnode **ppNode, const string& inWord)
{
    if (!*ppNode)//empty tree || not found,new number
    {
        //create a new node
        *ppNode = new Tnode_chged;
        (*ppNode)->word = new char[inWord.size() + 1];//1 more place for '\0'
        (*ppNode)->word=inWord;
        (*ppNode)->left = nullptr;
        (*ppNode)->right = nullptr;
        (*ppNode)->count = 1;//first appear
        return;//finish
    }
    //bigger or smaller
    int flag= inWord.compare((*ppNode)->word);
    if (flag < 0)
        dsNode(&(*ppNode)->left, inWord);
    else if (flag > 0)
        dsNode(&(*ppNode)->right, inWord);
    else
        (*ppNode)->count++;//another appear
}
void dsNode(Tnode_chged **ppNode, const string& inWord)
{
    if (!*ppNode)//empty tree || not found,new number
    {
        //create a new node
        *ppNode = new Tnode_chged;
        (*ppNode)->c_word = new char[inWord.size() + 1];//1 more place for '\0'
        strcpy((*ppNode)->c_word, inWord.c_str());
        (*ppNode)->left = nullptr;
        (*ppNode)->right = nullptr;
        (*ppNode)->count = 1;//first appear
        return;//finish
    }
    //bigger or smaller
    int flag= strcmp(inWord.c_str(), ((*ppNode))->c_word);
    if (flag < 0)
        dsNode((Tnode_chged**)&(*ppNode)->left, inWord);
    else if (flag > 0)
        dsNode((Tnode_chged**)&(*ppNode)->right, inWord);
    else
        (*ppNode)->count++;//another appear
}

//print
void PrintTree(Tnode* inNode)
{
    if(!inNode) return;
    //middle order
    PrintTree(inNode->left);
    cout << inNode->word << " :" << inNode->count << endl;
    PrintTree(inNode->right);
}
void PrintTree(Tnode_chged* inNode)
{
    if(!inNode) return;
    //middle order
    PrintTree((Tnode_chged*)inNode->left);
    cout << ((Tnode_chged*)inNode)->c_word << " :" << inNode->count << endl;
    PrintTree((Tnode_chged*)inNode->right);
}

int main(int argc, char** argv)
{
//    int argc=5;
//    char argv[5][3]={"oo", "ci", "au", "bf", "dm"};

    Tnode* root= nullptr;
    Tnode_chged* root_chged= nullptr;

    for(int i = 1; i < argc; i++)
    {
        dsNode(&root, string(argv[i]));
        dsNode(&root_chged, string(argv[i]));
    }
    //print
    cout << "pre-Change:" << endl;
    PrintTree(root);
    cout << endl;
    cout << "aft-Change:" << endl;
    PrintTree(root_chged);

    return 0;
}
