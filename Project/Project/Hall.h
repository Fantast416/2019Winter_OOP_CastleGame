#ifndef Hall_H
#define Hall_H
#include"Room.h"
class Hall :public Room {
public:
	void print();				//子类override父类，打印房间信息与剧情
};
#endif