#include"Garden.h"
extern Roomp ptr[17];
extern int prin;
extern int mons;
extern int flagkey;
/*
函数名：print
返回值类型： void
返回值描述： 无
所需参数描述: 无
函数功能： 输出该房间剧情及信息
*/
void Garden::print() {
	cout << "You come to a garden\n" << endl;
	if (this->ifprincess() && !flagkey) cout << "You find princess! But the princess was imprisoned by a shackl\n\nPlease find the key first\n" << endl;
	else if (this->ifprincess() && flagkey) cout << "You find princess! Oh! You have brought back the key!\n\nYou opend the lock with the key! \n\nNow!Take the princess out of the castle!!\n" << endl;
	else if (this->key) cout << "Oh! You find a key!It can be used to rescue the princess!\n" << endl;
	else if (this->ifmonster()) cout << "Oh! This room has a monster! You died!\n" << endl;
	else if (this->iftool()) cout << "Suprise!This room has some information for you!\n\nthe pricess are on the layer " << ptr[prin]->get_layer() << endl << endl;
	else if (this->iftool2()) cout << "Suprise!This room has some information for you!\n\nthe monster are on the layer " << ptr[mons]->get_layer() << endl << endl;
	else cout << "This garden has nothing special\n" << endl;
	if (!this->ifmonster()) {
		cout << "Following are the exits: Please choose one to go(enter one of them)\n" << endl;
		map<string, Room*>::iterator it;
		for (it = way.begin(); it != way.end(); it++) {
			cout << it->first << " ";
		}
		cout << endl;
		cout << endl;
	}
}