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
typedef Tnode* PTnode;

class Tnode_chged : public Tnode{//change the type of 'word'
public:
    char* c_word;//char* is a ptr of a char array.
};

//use binary sorted tree.
//dynamic search
void dsNode(PTnode& pNode, const string& inWord)
{
    if (!pNode)//empty tree || not found,new number
    {
        //create a new node
        if(typeid(*pNode) == typeid(Tnode_chged)) {
            pNode = new Tnode_chged;
            ((Tnode_chged*)pNode)->c_word = new char[inWord.size() + 1];//1 more place for '\0'
            strcpy(((Tnode_chged*)pNode)->c_word, inWord.c_str());
        } else{
            pNode = new Tnode;
            pNode->word=inWord;
        }
        pNode->left = nullptr;
        pNode->right = nullptr;
        pNode->count = 1;//first appear
        return;
    }
    //
    int flag;//bigger or smaller
    if(typeid(*pNode) == typeid(Tnode_chged)) {
        flag = strcmp(inWord.c_str(), ((Tnode_chged*)pNode)->c_word);
    } else{
        flag= inWord.compare(pNode->word);
    }
    if (flag < 0)
        dsNode(pNode->left, inWord);
    else if (flag > 0)
        dsNode(pNode->right, inWord);
    else
        pNode->count++;//another appear
}

void PrintTree(Tnode* inNode)
{
    if(!inNode) return;
    //middle order
    PrintTree(inNode->left);
    if(typeid(*inNode)==typeid(Tnode_chged)) {
        cout << ((Tnode_chged*)inNode)->c_word << " :" << inNode->count << endl;
    } else{
        cout << inNode->word << " :" << inNode->count << endl;
    }
    PrintTree(inNode->right);
}

int main()//int argc, char** argv
{
    int ac=5;
    char av[5][3]={"oo", "ci", "au", "bf", "dm"};

    Tnode* root= nullptr;
    Tnode_chged* root_chged= nullptr;

    dsNode(root, string(av[1]));;
    dsNode(root_chged, string(av[1]));

    for(int i = 1; i < ac; i++)
    {
        dsNode(root, string(av[i]));
        Tnode* p_root_chged=root_chged;
        dsNode(p_root_chged, string(av[i]));
    }
    PrintTree(root);
    cout << endl << endl;
    PrintTree(root_chged);

    return 0;
}
