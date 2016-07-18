#ifndef __ROLE__
#define __ROLE__
#include "cocos2d.h"

class Role : public cocos2d::Node
{
private:
	/*��ʾ*/
	cocos2d::Sprite* sharacter;
	/*cocos�Դ�����*/
	cocos2d::AnimationCache* animationList;
	/*jump�߶�*/
	float jumpH = 100.0f;
	/*jump����*/
	float jumpW = 200.0f;
	/*��ƽ��*/
	float horizon = 50.0f;
	/*״̬ 0 stand 1 lrun 2 rrun 3jump*/
	int state=0;
	int oldstate=-1;
	/*�ٶ�*/
	int speed = 2;
	/*��ǰ����action*/
	cocos2d::ActionInterval* runAct;
	
	/**/
	
public:
	Role();
	virtual bool init();
	~Role();
	bool up = false;
	/*վ��*/
	void stand(); 
	/*����*/
	void running(bool scale);
	/*��Ծ*/
	void jump();
	/*��������*/
	cocos2d::Animation* generateAnimate(char* file,char* name,float width,float height,int blocks,int speed);
	/*start*/
	void start();
	/*�ı�״̬*/
	void changeState(int s);
	/*storeAction*/
	void storeAct(cocos2d::Action* act);
	
	CREATE_FUNC(Role);
};

#endif
