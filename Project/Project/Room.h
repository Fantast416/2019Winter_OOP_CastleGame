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
		int layer;							 //�������ڲ���
		int monster;						 //�÷����й�������Ϊ1���޹�������Ϊ0
		int princess;						 //�÷����й�������Ϊ1���޹�������Ϊ0
		int tool;							 //�÷����ǵ��߷�������Ϊ1����������Ϊ0
		int tool2;							 //�÷����ǵ��߷�������Ϊ1����������Ϊ0
		int key;							 //�÷�����Կ������Ϊ1����������Ϊ0
	public:	
		Room();
		Room* get_mapinfo(string s);		 //��ȡ��һ����ͼ��Ϣ����
		int ifmonster();					 //�жϴ˷����Ƿ��й���
		int ifprincess();					 //�жϴ˷����Ƿ��й���
		int iftool();						 //�жϴ˷����Ƿ��й�����ʾ
		int iftool2();						 //�жϴ˷����Ƿ��й�����ʾ
		int ifkey();                         //�жϴ˷����Ƿ���Կ��
		void set_out(string s,Room* k);		 //���ó��ڣ��ڳ�ʼ��ʱ�õ�
		void set_princess();				 //����Ϊprincess���ڷ���
		void set_monster();					 //����Ϊmonster���ڷ���
		void set_tool();					 //����Ϊ���߷���
		void set_tool2();					 //����Ϊ���߷���
		void set_key();						 //����ΪԿ�����ڷ���
		void set_id(int id);				 //���ø÷���id���ڳ�ʼ��ʱ�õ�
		virtual void print();				 //�麯������ӡ������Ϣ�����
	 	int get_id();						 //���ʸ÷���id
		int get_layer();					 //���ʸ÷������ڲ���
		int monster_warning();				 //�ж��Ա߷����Ƿ��й���
		int princess_congradulate();		 //�ж��Ա߷����Ƿ��й���
};
typedef Room* Roomp;
#endif

