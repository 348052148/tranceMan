#include "Role.h"
USING_NS_CC;

Role::Role()
{
	
}

bool Role::init() {
	this->sharacter = Sprite::create();
	this->setPositionX(this->horizon);
	this->setPositionY(this->horizon);

	this->addChild(this->sharacter);

	this->animationList = AnimationCache::getInstance();
	
	this->state = 0;

	return true;
}

void Role::storeAct(cocos2d::Action* act) {
	if (this->runAct != NULL) {
		//this->sharacter->stopAction(this->runAct);
	}
	//this->runAct = act;
}

void Role::stand() {
	auto stand = this->generateAnimate("stand.png", "stand", 600.0f, 99.0f, 12,48);
	auto  act = RepeatForever::create(Animate::create(stand));
	this->runAct = act;
	this->sharacter->runAction(act);
}

void Role::running(bool scale) {
	auto running = this->generateAnimate("forward.png", "running", 744.0f, 99.0f, 8,64);
	auto move = MoveTo::create(5, Vec2(400, 50));
	auto act = Animate::create(running);
	//auto spawnAction = Spawn::create(move, run, NULL);
	if (scale) {
		this->sharacter->setScaleX(-1);
	}
	else {
		this->sharacter->setScaleX(1);
	}
	this->runAct = act;
	this->sharacter->runAction(act);
}

void Role::jump() {
	
	this->generateAnimate("stand.png", "stand", 600.0f, 99.0f, 12, 48);
	auto jump = JumpBy::create(1, Vec2(0, 0), this->jumpH, 1);
	this->sharacter->setDisplayFrameWithAnimationName("stand", 1);
	this->sharacter->runAction(jump);
}

cocos2d::Animation* Role::generateAnimate(char* file, char * name,float width, float height, int blocks,int speed) {
	auto anim = this->animationList->getAnimation(name);
	if (anim == NULL) {
		float w = width / blocks;
		auto spfLits = SpriteFrameCache::getInstance();
		auto repair = (int)speed / blocks;
		for (int i = 0; i < blocks; i++)
		{
			Rect rect = Rect(i*w, 0.0f, w, height);
			auto spf = SpriteFrame::create(file, rect);
			spfLits->addSpriteFrame(spf, name + i);
		}

		auto animate = Animation::create();
		animate->setLoops(1000);
		animate->setDelayPerUnit((float)1 / speed);
		animate->setRestoreOriginalFrame(true);
		for (int i = 0; i < blocks; i++) {
			for (int j = 0; j < repair; j++) {
				animate->addSpriteFrame(spfLits->getSpriteFrameByName(name + i));
			}
		}
		this->animationList->addAnimation(animate, name);
		anim = animate;
	}
	return anim;
}
void Role::changeState(int s) {
	
	this->state = s;
	/*
	if (this->state != this->oldstate && this->up) {
		this->up = false;
		this->sharacter->stopAction(this->runAct);
	}
	*/	
}
void Role::start() {
	switch (this->state) {
	case 1:
		this->setPositionX(this->getPositionX() - this->speed);
		break;
	case 2:
		this->setPositionX(this->getPositionX() + this->speed);
		break;
	}
	if (this->oldstate == this->state) return;
	switch (this->state) {
		case 0:
			this->stand();
			this->oldstate = 0;
			break;
		case 1:
			this->running(true);
			this->oldstate = 1;
			break;
		case 2:
			this->running(false);
			this->oldstate = 2;
			break;
		case 3:
			this->jump();
			this->oldstate = 3;
			break;
	}
	
}
Role::~Role()
{
}
