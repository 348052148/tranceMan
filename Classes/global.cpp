#include "global.h"
Global::Global() {
	this->mapObj = new cocos2d::Map<char*, cocos2d::Ref>();
}
Global * Global::getInstance() {
	return new Global();
}
void Global::set(char* key, cocos2d::Ref val) {

}
void Global::get(char* key, cocos2d::Ref val) {

}