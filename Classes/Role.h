#ifndef __ROLE__
#define __ROLE__
#include "cocos2d.h"

class Role : public cocos2d::Node
{
private:
	/*显示*/
	cocos2d::Sprite* sharacter;
	/*cocos自带但例*/
	cocos2d::AnimationCache* animationList;
	/*jump高度*/
	float jumpH = 100.0f;
	/*jump距离*/
	float jumpW = 200.0f;
	/*地平线*/
	float horizon = 50.0f;
	/*状态 0 stand 1 lrun 2 rrun 3jump*/
	int state=0;
	int oldstate=-1;
	/*速度*/
	int speed = 2;
	/*当前运行action*/
	cocos2d::ActionInterval* runAct;
	
	/**/
	
public:
	Role();
	virtual bool init();
	~Role();
	bool up = false;
	/*站立*/
	void stand(); 
	/*奔跑*/
	void running(bool scale);
	/*跳跃*/
	void jump();
	/*生产动画*/
	cocos2d::Animation* generateAnimate(char* file,char* name,float width,float height,int blocks,int speed);
	/*start*/
	void start();
	/*改变状态*/
	void changeState(int s);
	/*storeAction*/
	void storeAct(cocos2d::Action* act);
	
	CREATE_FUNC(Role);
};

#endif
