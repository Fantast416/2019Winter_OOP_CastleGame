#pragma warning(disable:4996)
#include<iostream>
#include<stdlib.h>
#include<string>
#include<ctime>
#include<windows.h> 
#include"Bedroom.h"
#include"Room.h"
#include"Study.h"
#include"Balcony.h"
#include"Stairs.h"
#include"Garden.h"
#include"Hall.h"
using namespace std;
void initilize();
void gameintroduction();
void gamestart();		
Room bornplace;			//玩家出生地(城堡外的gate)
Roomp ptr[17];          //其中ptr[0]指向城堡外 
Roomp now,last;			//玩家当前所在房间与玩家上一个房间
int flag;				//判断玩家是否已经带着princess(1为已经带着princess,0为还未找到princess)
int flag2;				//判断上一局游戏胜利还是输了 
int flagkey;			//判断玩家是否找到了钥匙
int tool;				//第一个提示房间所在位置（提示公主所在房间楼层）
int tool2;				//第二个提示房间所在位置（提示怪物所在房间楼层）
int key;				//钥匙所在房间
int prin;				//公主所在房间
int mons;				//怪物所在房间
Study study[3];			//三个书房对象
Bedroom bedroom[4];		//四个卧室对象
Balcony balcony[4];		//四个阳台对象
Garden garden;			//一个花园对象
Stairs stairs[2];		//两个楼梯对象
Hall hall[2];			//两个大厅对象
int main(){
    initilize();
    gameintroduction();
	gamestart();
}
/*
函数名： gameintroduction
返回值类型：  void
函数功能： 游戏具体情况介绍
*/
void gameintroduction(){
	cout<<"                                                  Welcome to this game!"<<endl;
	cout<<"\n                                        In this game,you will play the role of warrior,\n                          break into an unknown castle,and rescue the trapped princess in the castle. "<<endl;
	cout<<"\n                                        Note: there are two floors in the castle. \n                             You can enter the corresponding command to go up and down the stairs. "<<endl;
	cout<<"\n                               Monsters will be randomly generated somewhere in the castle. \n                                                 Please avoid them!"<<endl;
	cout<<"\n                                    When you find the princess, you still need to take\n                        the princess out of the castle according to the safe route to be successful."<<endl;
    cout<<"\n           There are also randomly reward rooms that will give you some information about princess or monsters!"<<endl;
    cout<<"\n                   Also, when you are closing to the princess or monsters,I will also give you some tips!"<<endl;
    cout<<"\n                                                    GOOD Luck!"<<endl;
    cout<<endl;
}
/*
函数名： gamestart
返回值类型：  void
函数功能： 开始游戏，游戏运行主函数
*/
void gamestart(){
	cout<<endl;
	string s;		//接收移动指令
	string temp;	//接收游戏结束后的指令
	string st;		//接收游戏最开始是start or quit
	cout<<"                            Now you are at the gate of a castle,Please start your adventure!\n\n                                         (print \"start\" to start your game)\n\n                                          (print \"quit\" to quit the game)\n"<<endl;
	label:          //设置标签
		cin>>st;
		if(st=="start"){							//如果玩家输入start，则开始游戏
			system("cls");							//清空控制台
			now = ptr[0];							//初始化now函数
			ptr[0]->print();						//打印出生点情况
			cout<<endl;								//换行（格式美观）
			while(cin>>s){							//进入接受游戏指令
				system("color F0");
				last = now;							//记录当前房间
				now = now->get_mapinfo(s);			//now跳转到，玩家指令输入后的下一个房间
				if(now == NULL){					//如果now为空
					cout<<"You have choose the wrong exits,please enter again correctly!"<<endl;
					now = last;				
					continue;						//直接要求重新输入命令
				}
				else system("cls");					//进入下一个房间，清空控制台
				if(now == ptr[0] && flag==1){		//游戏获胜条件
					cout<<endl;
					cout<<"You have rescued the principle!Great!"<<endl;
					flag2 = 1;
					break;
				}
				if(now->monster_warning()){			//如果周围房间有怪物存在，进行提醒
					system("color F4");				//设置控制台字体颜色为红色
					cout<<"Warning!!monster are around you!\n"<<endl;;
				}
				if(now->princess_congradulate()){	//如果公主在周围房间，进行提醒
					system("color F2");				//设置控制台字体颜色为绿色
					cout<<"Hey! the princess is besides you\n"<<endl;	
				}
				now->print();						//打印当前房间信息
				if(now->ifmonster()) {				//如果碰上了怪物
					flag2 = 0;						//flag2置0 并跳出循环
					break;				
				}
				if (now->ifkey())				flagkey = 1;
				if(now->ifprincess()&&flagkey)  flag=1;		//如果碰上了公主并且有钥匙，flag置1
			}
		}else if(st=="quit"){					//如果玩家输入quit，触发剧情
			cout<<"You are timid!!!!!You lost the chance to rescue the beautiful principle!!!"<<endl;
		}else{									//如果玩家输入除quit和start之外的指令，利用goto返回上述label标签所在，重新输入
			cout<<"you have entered a undefined command! Please enter again"<<endl;
			goto label;      
		}
		if(flag2==0){							//如果跳出循环后flag2为0，游戏失败，给出剧情
			cout<<"\nWarrior,you have failed rescuing the princess! Don't be discouraged!\n\nDo you want to play again?(print yes to go,print no to quit)\n"<<endl;
		}else{									//如果跳出循环后flag2为1，游戏成功，给出剧情
			cout<<"Congratulations! You have rescued the princess from this castal !\n\nDo you want to play again?(print yes to go,print no to quit)\n"<<endl;
		}
		while(cin>>temp){						//游戏结束后，接收玩家是否愿意重新游戏的指令
			if(temp=="yes"){
				break;
			}else if(temp=="no"){
				break;
			}else{
				cout<<"you have entered a undefined command! Please enter again"<<endl;
			}
		}		
		if(temp=="yes"){						//如果玩家输入yes，则初始化界面，重新调用该函数
			initilize();
			gamestart();
		}
}
/*
函数名： initilize
返回值类型：  void
函数功能： 初始化游戏界面及参数，随机生成怪物和公主以及工具房间
*/
void initilize(){
	unsigned seed;
	int i;
	flag = 0;
	flag2 = 0;
	SetConsoleTitle("SLKS's castal game");  //设置控制台窗口标题
	system("color F0");                     //设置控制台颜色
	system("cls");							//控制台清空
	seed = time(0);							//生成随机数种子
	srand(seed);							//利用随机数种子重置随机数
	//  随机产生monster 和 princess 所在的房间的编号 
	prin = rand()%16 + 1;					
	mons = rand()%16 + 1;
	tool = rand()%16 + 1;
	tool2 = rand()%16 + 1;
	key = rand() % 16 + 1;
	//将公主与怪物生成在一个房间中的情况剔除，将怪物生成在交通要道的情况删除，将工具房间和怪物公主房间重合的情况删除
	while(mons==2||mons==11||mons==7){
		mons = rand()%16 + 1;
	}	
    while(mons == prin){
    	prin = rand()%16 + 1;
	}
	while(tool==mons||tool==prin){
		tool = rand()%16 + 1;
	}
	while(tool2==mons||tool2==prin){
		tool2 = rand()%16 + 1;
	}
	while (key == mons || key == prin) {
		key = rand() % 16 + 1;
	}
	//cout << "mons:" << mons;
	//cout << "princess:" << prin;
	//cout << "tool:" << tool;
	//cout << "key" << key;
//初始化地图，将其与ptr指针数组联系起来，并且设置周围环境 
    bornplace.set_id(0);
	ptr[0] = &bornplace;  
    bedroom[0].set_id(5);
    ptr[5] = &bedroom[0];
	bedroom[1].set_id(8);
	ptr[8] = &bedroom[1];
	bedroom[2].set_id(10);
	ptr[10] = &bedroom[2];
	bedroom[3].set_id(15);
	ptr[15] = &bedroom[3];
	study[0].set_id(6);
	ptr[6] = &study[0];
	study[1].set_id(14);
	ptr[14] = &study[1];
	study[2].set_id(16);
	ptr[16] = &study[2];
	balcony[0].set_id(1);
	ptr[1] = &balcony[0];
	balcony[1].set_id(4);
	ptr[4] = &balcony[1];
	balcony[2].set_id(9);
	ptr[9] = &balcony[2];
	balcony[3].set_id(13);
	ptr[13] = &balcony[3];
	garden.set_id(3);
	ptr[3] = &garden;
	stairs[0].set_id(2);
	ptr[2] = &stairs[0];
	stairs[1].set_id(11);
	ptr[11] = &stairs[1];
	hall[0].set_id(7);
	ptr[7] = &hall[0];
	hall[1].set_id(12);
	ptr[12] = &hall[1];
    bornplace.set_out("west",ptr[7]);
    balcony[0].set_out("south",ptr[3]);
	stairs[0].set_out("east",ptr[3]);
	stairs[0].set_out("up",ptr[11]);
	stairs[0].set_out("south",ptr[6]);
	garden.set_out("north",ptr[1]);
	garden.set_out("west",ptr[2]);
	garden.set_out("east",ptr[4]);
	garden.set_out("south",ptr[7]);
	balcony[1].set_out("west",ptr[3]);
	bedroom[0].set_out("east",ptr[6]);
	study[0].set_out("north",ptr[2]);
	study[0].set_out("west",ptr[5]);
	study[0].set_out("east",ptr[7]);
	hall[0].set_out("north",ptr[3]);
	hall[0].set_out("west",ptr[6]);
	hall[0].set_out("east",ptr[0]);
	hall[0].set_out("south",ptr[8]);
	bedroom[1].set_out("north",ptr[7]);
	balcony[2].set_out("south",ptr[12]);
	balcony[3].set_out("west", ptr[12]);
	bedroom[2].set_out("east",ptr[11]);
	bedroom[2].set_out("south",ptr[14]);
	stairs[1].set_out("down",ptr[2]);
	stairs[1].set_out("west",ptr[10]);
	stairs[1].set_out("east",ptr[12]);	
	stairs[1].set_out("south",ptr[15]);
	hall[1].set_out("north",ptr[9]);
	hall[1].set_out("west",ptr[11]);
	hall[1].set_out("south",ptr[16]);
	hall[1].set_out("east",ptr[13]);
	study[1].set_out("north",ptr[10]);
	study[1].set_out("east",ptr[15]);
	bedroom[3].set_out("north",ptr[11]);
	bedroom[3].set_out("west",ptr[14]);
	study[2].set_out("north",ptr[12]);	
//在怪物、公主、工具房间生成的对应编号的对象中调用函数设置情况
	for(i=1;i<=16;i++){
		if(mons == i){
			ptr[i]->set_monster();
		}
		if(prin == i){
			ptr[i]->set_princess();
		}
		if(tool == i){
			ptr[i]->set_tool();
		}
		if(tool2 == i){
			ptr[i]->set_tool2();
		}
		if (key == i) {
			ptr[i]->set_key(); 
		}
	}
}
