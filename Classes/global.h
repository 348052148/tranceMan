#ifndef __GLOBAL__
#define __GLOBAL__
#include "cocos2d.h"
class Global {
private:
	Global();
	cocos2d::Map<char*,cocos2d::Ref>* mapObj;
public:
	Global * getInstance();
	void set(char* key, cocos2d::Ref val);
	void get(char* key, cocos2d::Ref val);
};
#endif
