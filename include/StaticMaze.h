#ifndef STATICMAZE_H
#define STATICMAZE_H

#include"Stack.h"

class StaticMaze
{
    public:
        StaticMaze();
        virtual ~StaticMaze();
        void display();
        void print(int a);
        Ordi getEntrance();
        Ordi getExit();
        bool pass(Ordi cur,Stack s);
        Ordi nextPos(Ordi cur,int c);
        bool match(Ordi a,Ordi b);
        void showPath(Stack s);
    protected:

    private:
        int m[10][10];
        Ordi entrance;
        Ordi exit;
};

#endif // STATICMAZE_H
