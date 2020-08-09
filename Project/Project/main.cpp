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
Room bornplace;			//��ҳ�����(�Ǳ����gate)
Roomp ptr[17];          //����ptr[0]ָ��Ǳ��� 
Roomp now,last;			//��ҵ�ǰ���ڷ����������һ������
int flag;				//�ж�����Ƿ��Ѿ�����princess(1Ϊ�Ѿ�����princess,0Ϊ��δ�ҵ�princess)
int flag2;				//�ж���һ����Ϸʤ���������� 
int flagkey;			//�ж�����Ƿ��ҵ���Կ��
int tool;				//��һ����ʾ��������λ�ã���ʾ�������ڷ���¥�㣩
int tool2;				//�ڶ�����ʾ��������λ�ã���ʾ�������ڷ���¥�㣩
int key;				//Կ�����ڷ���
int prin;				//�������ڷ���
int mons;				//�������ڷ���
Study study[3];			//�����鷿����
Bedroom bedroom[4];		//�ĸ����Ҷ���
Balcony balcony[4];		//�ĸ���̨����
Garden garden;			//һ����԰����
Stairs stairs[2];		//����¥�ݶ���
Hall hall[2];			//������������
int main(){
    initilize();
    gameintroduction();
	gamestart();
}
/*
�������� gameintroduction
����ֵ���ͣ�  void
�������ܣ� ��Ϸ�����������
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
�������� gamestart
����ֵ���ͣ�  void
�������ܣ� ��ʼ��Ϸ����Ϸ����������
*/
void gamestart(){
	cout<<endl;
	string s;		//�����ƶ�ָ��
	string temp;	//������Ϸ�������ָ��
	string st;		//������Ϸ�ʼ��start or quit
	cout<<"                            Now you are at the gate of a castle,Please start your adventure!\n\n                                         (print \"start\" to start your game)\n\n                                          (print \"quit\" to quit the game)\n"<<endl;
	label:          //���ñ�ǩ
		cin>>st;
		if(st=="start"){							//����������start����ʼ��Ϸ
			system("cls");							//��տ���̨
			now = ptr[0];							//��ʼ��now����
			ptr[0]->print();						//��ӡ���������
			cout<<endl;								//���У���ʽ���ۣ�
			while(cin>>s){							//���������Ϸָ��
				system("color F0");
				last = now;							//��¼��ǰ����
				now = now->get_mapinfo(s);			//now��ת�������ָ����������һ������
				if(now == NULL){					//���nowΪ��
					cout<<"You have choose the wrong exits,please enter again correctly!"<<endl;
					now = last;				
					continue;						//ֱ��Ҫ��������������
				}
				else system("cls");					//������һ�����䣬��տ���̨
				if(now == ptr[0] && flag==1){		//��Ϸ��ʤ����
					cout<<endl;
					cout<<"You have rescued the principle!Great!"<<endl;
					flag2 = 1;
					break;
				}
				if(now->monster_warning()){			//�����Χ�����й�����ڣ���������
					system("color F4");				//���ÿ���̨������ɫΪ��ɫ
					cout<<"Warning!!monster are around you!\n"<<endl;;
				}
				if(now->princess_congradulate()){	//�����������Χ���䣬��������
					system("color F2");				//���ÿ���̨������ɫΪ��ɫ
					cout<<"Hey! the princess is besides you\n"<<endl;	
				}
				now->print();						//��ӡ��ǰ������Ϣ
				if(now->ifmonster()) {				//��������˹���
					flag2 = 0;						//flag2��0 ������ѭ��
					break;				
				}
				if (now->ifkey())				flagkey = 1;
				if(now->ifprincess()&&flagkey)  flag=1;		//��������˹���������Կ�ף�flag��1
			}
		}else if(st=="quit"){					//����������quit����������
			cout<<"You are timid!!!!!You lost the chance to rescue the beautiful principle!!!"<<endl;
		}else{									//�����������quit��start֮���ָ�����goto��������label��ǩ���ڣ���������
			cout<<"you have entered a undefined command! Please enter again"<<endl;
			goto label;      
		}
		if(flag2==0){							//�������ѭ����flag2Ϊ0����Ϸʧ�ܣ���������
			cout<<"\nWarrior,you have failed rescuing the princess! Don't be discouraged!\n\nDo you want to play again?(print yes to go,print no to quit)\n"<<endl;
		}else{									//�������ѭ����flag2Ϊ1����Ϸ�ɹ�����������
			cout<<"Congratulations! You have rescued the princess from this castal !\n\nDo you want to play again?(print yes to go,print no to quit)\n"<<endl;
		}
		while(cin>>temp){						//��Ϸ�����󣬽�������Ƿ�Ը��������Ϸ��ָ��
			if(temp=="yes"){
				break;
			}else if(temp=="no"){
				break;
			}else{
				cout<<"you have entered a undefined command! Please enter again"<<endl;
			}
		}		
		if(temp=="yes"){						//����������yes�����ʼ�����棬���µ��øú���
			initilize();
			gamestart();
		}
}
/*
�������� initilize
����ֵ���ͣ�  void
�������ܣ� ��ʼ����Ϸ���漰������������ɹ���͹����Լ����߷���
*/
void initilize(){
	unsigned seed;
	int i;
	flag = 0;
	flag2 = 0;
	SetConsoleTitle("SLKS's castal game");  //���ÿ���̨���ڱ���
	system("color F0");                     //���ÿ���̨��ɫ
	system("cls");							//����̨���
	seed = time(0);							//�������������
	srand(seed);							//����������������������
	//  �������monster �� princess ���ڵķ���ı�� 
	prin = rand()%16 + 1;					
	mons = rand()%16 + 1;
	tool = rand()%16 + 1;
	tool2 = rand()%16 + 1;
	key = rand() % 16 + 1;
	//�����������������һ�������е�����޳��������������ڽ�ͨҪ�������ɾ���������߷���͹��﹫�������غϵ����ɾ��
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
//��ʼ����ͼ��������ptrָ��������ϵ����������������Χ���� 
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
//�ڹ�����������߷������ɵĶ�Ӧ��ŵĶ����е��ú����������
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
