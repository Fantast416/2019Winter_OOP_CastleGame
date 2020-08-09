#ifndef Balcony_H
#define Balcony_H
#include"Room.h"
	class Balcony :public Room {
		public:
			void print();				//子类override父类，打印房间信息与剧情
	};
#endif