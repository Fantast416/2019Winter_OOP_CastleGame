#ifndef Stairs_H
#define Stairs_H
#include"Room.h"
class Stairs :public Room {
public:
	void print();				//子类override父类，打印房间信息与剧情
};
#endif