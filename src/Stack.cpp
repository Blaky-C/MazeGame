#include "Stack.h"
#include<iostream>
using namespace std;

Stack::Stack()
{
    base = new Ordi[STACK_INIT_SIZE];
    top = base;
    stackSize = STACK_INIT_SIZE;
    length = 0;
}

Stack::~Stack()
{
    while( top != base){
        delete (--top);
    }
    base = NULL;
    top = NULL;
    length = stackSize = 0;
}

bool Stack::stackEmpty(){
    if (top == base) return true;
    return false;
}
Ordi Stack::getTop(){
    if (top == base){
        cout<<"EORROR!Stack is EMPTY!"<<endl;
        return *top;
    }
    return *(top-1);
}

void Stack::push(Ordi e){
    if (top - base >= stackSize){
        Ordi* temp = new Ordi[stackSize+STACKINCREMENT];
        for (int i=0;i < length;i++){
            temp[i] = base[i];
        }
        //释放栈的内存
        while( top != base){
            delete (--top);
        }
        base = temp;
        temp = NULL;
        top = base + length;
        stackSize += STACKINCREMENT;
    }

    length++;
    *(top++) = e;
}

Ordi Stack::pop(){
    if (top == base){
        cout<<"ERROR!Stack is EMPTY!"<<endl;
        return *top;
    }

    Ordi e = *(--top);
    delete top;
    length--;
    return e;
}

void Stack::traverseStack(){
    if (top == base){
        cout<<"Stack is Empty!"<<endl;
    }else{
        for (int i=0;i < length;i++){
            print(base[i]);
        }
        cout<<endl;
    }
}

void Stack::print(Ordi e){
    cout<<"("<<e.x<<", "<<e.y<<")"<<endl;
}

Ordi Stack::createNode(int x,int y,int di){
    Ordi* e = new Ordi();

    e->x = x;
    e->y = y;
    e->di = di;

    return *e;
}

int Stack::getLength(){
    return length;
}

Ordi Stack::getElem(int i){
    return *(base+i);
}
