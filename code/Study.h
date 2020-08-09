#ifndef STUDY_H
#define STUDY_H
#include"Room.h"
class Study :public Room {
public:
	void print();				//子类override父类，打印房间信息与剧情
};
#endif