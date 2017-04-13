#include"StaticMaze.h"
#include"Stack.h"
#include<iostream>
using namespace std;

int main(){
    //静态迷宫模型测试
	StaticMaze obj;
	obj.display();


	//栈类测试
	/*
	Stack obj;
	obj.traverseStack();

	obj.push(obj.createNode(1,1,1));
	obj.push(obj.createNode(2,1,1));
	obj.push((obj.createNode(3,1,1)));
	obj.traverseStack();
	obj.print(obj.getTop());

    obj.pop();
    obj.traverseStack();
    */

    Stack mazeStack;
    StaticMaze maze;

    Ordi curPos = maze.getEntrance();

    //cout<<curPos.x<<curPos.y<<endl;
    int step = 1;

    do{
        if ( maze.pass(curPos,mazeStack) ){
            mazeStack.push(curPos);
            //mazeStack.traverseStack();
            if (maze.match(curPos,maze.getExit())){
                cout<<"Get the Exit!"<<endl;
                cout<<"Show Path:"<<endl;
                maze.showPath(mazeStack);
                return 0;
            }
            curPos = maze.nextPos(curPos,1);//探索当前位置的东邻位置
            step++;
        }else if (!mazeStack.stackEmpty()){
            Ordi e = mazeStack.pop();
            while (e.di==4 && !mazeStack.stackEmpty()){
                e = mazeStack.pop();
            }
            if (e.di < 4){
                e.di++;
                mazeStack.push(e);
                //mazeStack.traverseStack();
                curPos = maze.nextPos(e,e.di);
            }
        }
    }while(!mazeStack.stackEmpty());

    cout<<"Maze can not find the Exit!"<<endl;

	return 0;
}
