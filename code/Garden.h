#ifndef Garden_H
#define Garden_H
#include"Room.h"
class Garden:public Room {
public:
	void print();		//子类override父类，打印房间信息与剧情
};
#endif