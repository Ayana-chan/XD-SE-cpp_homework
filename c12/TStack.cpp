#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

template <class T>
class Stack {
private:
    int MAXSIZE=1024;//biggest size allowed
    int SIZE=4;//max size now (list size)
    T* dataList=new T[SIZE];//data
    int pos=-1;//show the top of the stack (data size = pos+1)
    void expandSize();
public:
    Stack();//empty stack
    ~Stack();

    void push(const T &item);
    void pop();
    T& top();
    void clear();
    int size();

    bool isEmpty() const;
    bool isFull() const;
    bool isMax() const;
};

template <class T>
void Stack<T>::expandSize() {
    SIZE*=2;
    T* prel=dataList;
    dataList=new T[SIZE];
    for(int i=0; i <= pos; i++){
        dataList[i]=prel[i];
    }
    delete[] prel;
}

template <class T>
Stack<T>::Stack() = default;

template <class T>
Stack<T>::~Stack() {
    delete[] dataList;
}


template <class T>
void Stack<T>::push(const T &item) {
    assert(!isMax());
    if(isFull()){
        expandSize();
    }
    dataList[++pos] = item;
}

template <class T>
void Stack<T>::pop() {
    assert(!isEmpty());
    pos--;
}

template <class T>
T& Stack<T>::top() {
    assert(!isEmpty());
    return dataList[pos];
}

template <class T>
void Stack<T>::clear() {
    SIZE=4;
    delete[] dataList;
    dataList=new T[SIZE];
    pos = -1;
}

template <class T>
int Stack<T>::size() {
    return pos+1;
}


template <class T>
bool Stack<T>::isEmpty() const {
    return pos == -1;
}

template <class T>
bool Stack<T>::isFull() const {
    return pos == SIZE - 1;
}

template <class T>
bool Stack<T>::isMax() const {
    return pos == MAXSIZE - 1;
}


int main() {
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout << "size=" << s.size() << endl;
    while (!s.isEmpty()) {
        cout << s.top() << endl;
        s.pop();
    }

}

