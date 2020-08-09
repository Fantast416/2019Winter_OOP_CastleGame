#include"Room.h"
extern Roomp ptr[17];
extern int prin;
extern int mons;
/*
函数名：Room
返回值类型： 无
返回值描述： 无
所需参数描述: 无
函数功能： Room对象的初始化构造函数，初始化一些基本的信息
*/
Room::Room(){
			this->monster = 0 ;
			this->princess = 0;
			this->tool = 0;	
			this->tool2= 0;
		  	}
/*
函数名：get_mapinfo
返回值类型： Room*
返回值描述： 如找到，返回前往的房间的指针；如未找到，返回NULL
所需参数描述: string s,(s为east、west、north、south中的一个)
函数功能： 根据输入指令，返回按照该指令进行移动后的人物的房间指针
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
函数名：ifmonster
返回值类型： int
返回值描述： 如该房间有怪物存在，返回1；如无怪物存在，返回0
所需参数描述: 无
函数功能： 判断该房间是否有怪物存在
*/
int Room::ifmonster(){
			if(monster == 1) return 1;
			else return 0;
		}
/*
函数名：ifprincess
返回值类型： int
返回值描述： 如该房间有公主存在，返回1；如无公主存在，返回0
所需参数描述: 无
函数功能： 判断该房间是否有公主存在
*/
int Room::ifprincess(){
			if(princess == 1) return 1;
			else return 0;
		}
/*
函数名：iftool
返回值类型： int
返回值描述： 如该房间有道具存在，返回1；如无道具存在，返回0
所需参数描述: 无
函数功能： 判断该房间是否有道具存在
*/
int Room::iftool(){
			if(tool == 1) return 1;
			else return 0;
		}
/*
函数名：iftool2
返回值类型： int
返回值描述： 如该房间有道具存在，返回1；如无道具存在，返回0
所需参数描述: 无
函数功能： 判断该房间是否有道具存在
*/
int Room::iftool2(){
			if(tool2 == 1) return 1;
			else return 0;
		}
/*
函数名：ifkey
返回值类型： int
返回值描述： 如该房间有钥匙存在，返回1；如无钥匙存在，返回0
所需参数描述: 无
函数功能： 判断该房间是否有钥匙存在
*/
int Room::ifkey() {
	if (this->key == 1) return 1;
	else return 0;
}
/*
函数名：set_out
返回值类型： void
返回值描述： 无
所需参数描述: string s,(s为east、west、north、south中的一个),Room* k 房间指针
函数功能： 设置本房间中map里出口和对应出口房间的关系
*/
void Room::set_out(string s,Room* k){
			way[s]=k;
		} 
/*
函数名：set_princess
返回值类型： void
返回值描述： 无
所需参数描述: 无
函数功能： 设置本房间中生成一个公主
*/
void Room::set_princess(){
			this->princess = 1; 
		}
/*
函数名：set_monster
返回值类型： void
返回值描述： 无
所需参数描述: 无
函数功能： 设置本房间中生成一个怪物
*/
void Room::set_monster(){
			this->monster = 1;
		}
/*
函数名：set_tool
返回值类型： void
返回值描述： 无
所需参数描述: 无
函数功能： 设置本房间中生成一个道具
*/
void Room::set_tool(){
			this->tool = 1;
		}
/*
函数名：set_tool2
返回值类型： void
返回值描述： 无
所需参数描述: 无
函数功能： 设置本房间中生成一个道具
*/
void Room::set_tool2(){
			this->tool2= 1;
		}
/*
函数名：set_key
返回值类型： void
返回值描述： 无
所需参数描述: 无
函数功能： 设置本房间中生成一个可以解开公主所在牢笼的钥匙
*/
void Room::set_key() {
	this->key = 1;
}
/*
函数名：set_id
返回值类型： void
返回值描述： 无
所需参数描述: ind id 房间id
函数功能： 设置本房间的id，以及根据id设置该房间所在楼层
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
函数名：print
返回值类型： void
返回值描述： 无
所需参数描述: 无
函数功能： 输出该房间剧情及信息
*/
void Room::print(){
			map<string,Room*>::iterator it;
			cout<<"You are at the gate of the castal!\n"<<endl;
			cout<<"Following are the exits: Please choose one to go(enter one of them)\n"<<endl;
			for(it=way.begin();it!=way.end();it++){           //遍历map，输出出口
				cout<<it->first<<" ";
			}
			cout<<endl;
			cout<<endl;
		}
/*
函数名：get_id
返回值类型： int
返回值描述： 返回该房间id
所需参数描述: 无
函数功能：	返回该房间id
*/
int Room::get_id(){
			return this->id;
		}
/*
函数名：get_layer
返回值类型： int
返回值描述： 返回该房间layer
所需参数描述: 无
函数功能：	返回该房间layer
*/
int Room::get_layer(){
			return this->layer;
		}
/*
函数名：monster_warning
返回值类型： int
返回值描述： 若周围房间存在怪物则返回1，若无返回0
所需参数描述: 无
函数功能：	判断旁边房间是否有怪物
*/
int Room::monster_warning(){
			map<string,Room*>::iterator it;
			for(it=way.begin();it!=way.end();it++){
			 	if(it->second->ifmonster()) return 1;
			}
			return 0;	
		}
/*
函数名：princess_congradulate
返回值类型： int
返回值描述： 若周围房间存在公主则返回1，若无返回0
所需参数描述: 无
函数功能：	判断旁边房间是否有公主
*/
int Room::princess_congradulate(){
			map<string,Room*>::iterator it;
			for(it=way.begin();it!=way.end();it++){
			 	if(it->second->ifprincess()) return 1;
			}
			return 0;	
}



