#include "StaticMaze.h"
#include <iostream>
using namespace std;

StaticMaze::StaticMaze()
{
    //���ｫ�Թ���ʼ��Ϊ��̬�Թ���
		//��������P50
		//ǽ���ʾ: 0
		//ͨ����ʾ: 1
		//��ڱ�ʾ: -1
		//���ڱ�ʾ: 2

		int i,j;

		for (i=0;i < 10;i++){
			for (j=0;j < 10;j++){
				m[i][j] = 0;
			}
		}

		//1-2���Թ�
		for (i=1;i < 3;i++){
			for (j=1;j < 9;j++){
				if ((j != 3) && (j != 7)){
					m[i][j] = 1;
				}
			}
		}
		//��3���Թ�
		for (i=3;i < 4;i++){
			for (j=1;j < 9;j++){
				if ((j != 5) && (j != 6)){
					m[i][j] = 1;
				}
			}
		}
		//��4���Թ�
		for (i=4;i < 5;i++){
			for (j=1;j < 9;j++){
				if ((j != 2) && (j != 3) && (j != 4)){
					m[i][j] = 1;
				}
			}
		}
		//��5���Թ�
		for (i=5;i < 6;i++){
			for (j=1;j < 9;j++){
				if (j != 4){
					m[i][j] = 1;
				}
			}
		}
		//��6���Թ�
		for (i=6;i < 7;i++){
			for (j=1;j < 9;j++){
				if ((j != 2) && (j != 6)){
					m[i][j] = 1;
				}
			}
		}
		//��7���Թ�
		for (i=7;i < 8;i++){
			for (j=1;j < 9;j++){
				if ((j == 1) || (j == 5) || (j == 8)){
					m[i][j] = 1;
				}
			}
		}
		//��8���Թ�
		for (i=8;i < 9;i++){
			for (j=1;j < 9;j++){
				if (j != 1){
					m[i][j] = 1;
				}
			}
		}

		//�����ںͳ���
		//�ɳ���ȡ��������ںͳ��ڵ�˽�г�Ա����
		entrance.x = 1;
		entrance.y = 1;
		entrance.di = 1;
		m[1][1] = -1;
		exit.x = 8;
		exit.y = 8;
		exit.di = 1;
		m[8][8] = 2;
}

StaticMaze::~StaticMaze()
{
    //dtor
}

void StaticMaze::display(){
    for (int i=0;i < 10;i++){
        for (int j=0;j < 10;j++){
            print(m[i][j]);
        }
        cout<<endl;
    }
}

void StaticMaze::print(int a){
    switch (a){
		case 0:
			cout<<"��";
			break;
		case 1:
			cout<<"��";
			break;
		case -1:
			cout<<"��";
			break;
		case 2:
			cout<<"��";
			break;
        case 6:
            cout<<"��";
            break;
		default:
			cout<<endl<<"Init Eorror!"<<endl;
			break;
		}
}

Ordi StaticMaze::getEntrance(){
    return entrance;
}

Ordi StaticMaze::getExit(){
    return exit;
}

bool StaticMaze::pass(Ordi c,Stack s){
    //cout<<m[c.x][c.y]<<endl;
    if (c.x == 1 && c.y == 1) return true;//��ʼ�ڵ�ֱ���жϿ�ͨ��
    for(int i=0;i < s.getLength();i++){
        if ((s.getElem(i).x == c.x) && (s.getElem(i).y == c.y)){
            return false;
        }
    }

    if ( m[c.y][c.x] == 0){
        return false;
    }

    return true;
}

Ordi StaticMaze::nextPos(Ordi cur,int c){
    switch (c){
    case 1:
        cur.x++;
        break;
    case 2:
        cur.y++;
        break;
    case 3:
        cur.x--;
        break;
    case 4:
        cur.y--;
        break;
    default:
        break;
    }

    cur.di = 1;
    return cur;
}
bool StaticMaze::match(Ordi a,Ordi b){
    if ((a.x == b.x) && (a.y == b.y) ){
        return true;
    }
    return false;
}

void StaticMaze::showPath(Stack s){
    for (int i=1;i < s.getLength()-1;i++){
        int x = s.getElem(i).x;
        int y = s.getElem(i).y;
        m[y][x] = 6;
    }
    display();
}
