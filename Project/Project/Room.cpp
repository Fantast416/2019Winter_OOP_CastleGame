#include"Room.h"
extern Roomp ptr[17];
extern int prin;
extern int mons;
/*
��������Room
����ֵ���ͣ� ��
����ֵ������ ��
�����������: ��
�������ܣ� Room����ĳ�ʼ�����캯������ʼ��һЩ��������Ϣ
*/
Room::Room(){
			this->monster = 0 ;
			this->princess = 0;
			this->tool = 0;	
			this->tool2= 0;
		  	}
/*
��������get_mapinfo
����ֵ���ͣ� Room*
����ֵ������ ���ҵ�������ǰ���ķ����ָ�룻��δ�ҵ�������NULL
�����������: string s,(sΪeast��west��north��south�е�һ��)
�������ܣ� ��������ָ����ذ��ո�ָ������ƶ��������ķ���ָ��
*/
Room* Room::get_mapinfo(string s){
			map<string,Room*>::iterator it;
			it = way.find(s);
			if(it!=way.end())
				return it->second; 
			else
				return NULL;
		}
/*
��������ifmonster
����ֵ���ͣ� int
����ֵ������ ��÷����й�����ڣ�����1�����޹�����ڣ�����0
�����������: ��
�������ܣ� �жϸ÷����Ƿ��й������
*/
int Room::ifmonster(){
			if(monster == 1) return 1;
			else return 0;
		}
/*
��������ifprincess
����ֵ���ͣ� int
����ֵ������ ��÷����й������ڣ�����1�����޹������ڣ�����0
�����������: ��
�������ܣ� �жϸ÷����Ƿ��й�������
*/
int Room::ifprincess(){
			if(princess == 1) return 1;
			else return 0;
		}
/*
��������iftool
����ֵ���ͣ� int
����ֵ������ ��÷����е��ߴ��ڣ�����1�����޵��ߴ��ڣ�����0
�����������: ��
�������ܣ� �жϸ÷����Ƿ��е��ߴ���
*/
int Room::iftool(){
			if(tool == 1) return 1;
			else return 0;
		}
/*
��������iftool2
����ֵ���ͣ� int
����ֵ������ ��÷����е��ߴ��ڣ�����1�����޵��ߴ��ڣ�����0
�����������: ��
�������ܣ� �жϸ÷����Ƿ��е��ߴ���
*/
int Room::iftool2(){
			if(tool2 == 1) return 1;
			else return 0;
		}
/*
��������ifkey
����ֵ���ͣ� int
����ֵ������ ��÷�����Կ�״��ڣ�����1������Կ�״��ڣ�����0
�����������: ��
�������ܣ� �жϸ÷����Ƿ���Կ�״���
*/
int Room::ifkey() {
	if (this->key == 1) return 1;
	else return 0;
}
/*
��������set_out
����ֵ���ͣ� void
����ֵ������ ��
�����������: string s,(sΪeast��west��north��south�е�һ��),Room* k ����ָ��
�������ܣ� ���ñ�������map����ںͶ�Ӧ���ڷ���Ĺ�ϵ
*/
void Room::set_out(string s,Room* k){
			way[s]=k;
		} 
/*
��������set_princess
����ֵ���ͣ� void
����ֵ������ ��
�����������: ��
�������ܣ� ���ñ�����������һ������
*/
void Room::set_princess(){
			this->princess = 1; 
		}
/*
��������set_monster
����ֵ���ͣ� void
����ֵ������ ��
�����������: ��
�������ܣ� ���ñ�����������һ������
*/
void Room::set_monster(){
			this->monster = 1;
		}
/*
��������set_tool
����ֵ���ͣ� void
����ֵ������ ��
�����������: ��
�������ܣ� ���ñ�����������һ������
*/
void Room::set_tool(){
			this->tool = 1;
		}
/*
��������set_tool2
����ֵ���ͣ� void
����ֵ������ ��
�����������: ��
�������ܣ� ���ñ�����������һ������
*/
void Room::set_tool2(){
			this->tool2= 1;
		}
/*
��������set_key
����ֵ���ͣ� void
����ֵ������ ��
�����������: ��
�������ܣ� ���ñ�����������һ�����Խ⿪��������������Կ��
*/
void Room::set_key() {
	this->key = 1;
}
/*
��������set_id
����ֵ���ͣ� void
����ֵ������ ��
�����������: ind id ����id
�������ܣ� ���ñ������id���Լ�����id���ø÷�������¥��
*/
void Room::set_id(int id){
			this->id = id;
			if(id<=8&&id>=1){
				this->layer = 1;
			}else{
				this->layer = 2;
			}
		}
/*
��������print
����ֵ���ͣ� void
����ֵ������ ��
�����������: ��
�������ܣ� ����÷�����鼰��Ϣ
*/
void Room::print(){
			map<string,Room*>::iterator it;
			cout<<"You are at the gate of the castal!\n"<<endl;
			cout<<"Following are the exits: Please choose one to go(enter one of them)\n"<<endl;
			for(it=way.begin();it!=way.end();it++){           //����map���������
				cout<<it->first<<" ";
			}
			cout<<endl;
			cout<<endl;
		}
/*
��������get_id
����ֵ���ͣ� int
����ֵ������ ���ظ÷���id
�����������: ��
�������ܣ�	���ظ÷���id
*/
int Room::get_id(){
			return this->id;
		}
/*
��������get_layer
����ֵ���ͣ� int
����ֵ������ ���ظ÷���layer
�����������: ��
�������ܣ�	���ظ÷���layer
*/
int Room::get_layer(){
			return this->layer;
		}
/*
��������monster_warning
����ֵ���ͣ� int
����ֵ������ ����Χ������ڹ����򷵻�1�����޷���0
�����������: ��
�������ܣ�	�ж��Ա߷����Ƿ��й���
*/
int Room::monster_warning(){
			map<string,Room*>::iterator it;
			for(it=way.begin();it!=way.end();it++){
			 	if(it->second->ifmonster()) return 1;
			}
			return 0;	
		}
/*
��������princess_congradulate
����ֵ���ͣ� int
����ֵ������ ����Χ������ڹ����򷵻�1�����޷���0
�����������: ��
�������ܣ�	�ж��Ա߷����Ƿ��й���
*/
int Room::princess_congradulate(){
			map<string,Room*>::iterator it;
			for(it=way.begin();it!=way.end();it++){
			 	if(it->second->ifprincess()) return 1;
			}
			return 0;	
}



