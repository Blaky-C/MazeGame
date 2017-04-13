#ifndef STACK_H
#define STACK_H

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

struct Ordi{
	int x;
	int y;
	int di;//·�����
};

class Stack
{
    public:
        Stack();
        virtual ~Stack();
        bool stackEmpty();
        Ordi getTop();
        void push(Ordi e);
        Ordi pop();
        void traverseStack();
        void print(Ordi e);
        Ordi createNode(int x,int y,int di);//���������ű�ʾ����
        int getLength();
        Ordi getElem(int i);

    protected:

    private:
        Ordi* base;
        Ordi* top;
        int stackSize;
        int length;
};

#endif // STACK_H
