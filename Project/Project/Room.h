#ifndef ROOM_H
#define ROOM_H 
#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<windows.h> 
#include<map>
using namespace std;
class Room{
	protected:
		map<string,Room*> way;
	    int id;
		int layer;							 //房间所在层数
		int monster;						 //该房间有怪物设置为1，无怪物设置为0
		int princess;						 //该房间有公主设置为1，无怪物设置为0
		int tool;							 //该房间是道具房间设置为1，无则设置为0
		int tool2;							 //该房间是道具房间设置为1，无则设置为0
		int key;							 //该房间有钥匙设置为1，无则设置为0
	public:	
		Room();
		Room* get_mapinfo(string s);		 //获取下一个地图信息函数
		int ifmonster();					 //判断此房间是否有怪物
		int ifprincess();					 //判断此房间是否有公主
		int iftool();						 //判断此房间是否有工具提示
		int iftool2();						 //判断此房间是否有工具提示
		int ifkey();                         //判断此房间是否有钥匙
		void set_out(string s,Room* k);		 //设置出口，在初始化时用到
		void set_princess();				 //设置为princess所在房间
		void set_monster();					 //设置为monster所在房间
		void set_tool();					 //设置为工具房间
		void set_tool2();					 //设置为工具房间
		void set_key();						 //设置为钥匙所在房间
		void set_id(int id);				 //设置该房间id，在初始化时用到
		virtual void print();				 //虚函数，打印房间信息与剧情
	 	int get_id();						 //访问该房间id
		int get_layer();					 //访问该房间所在层数
		int monster_warning();				 //判断旁边房间是否有怪物
		int princess_congradulate();		 //判断旁边房间是否有公主
};
typedef Room* Roomp;
#endif

