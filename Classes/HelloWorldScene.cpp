#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "AppDelegate.h"
#include "Role.h"
USING_NS_CC;
static Role* roles;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	/*添加角色*/
	this->role = Role::create();
	this->addChild(role, 1);

	/*处理事件循环*/
	this->scheduleUpdate();
	
	roles = this->role;
	auto listener = EventListenerKeyboard::create();
	listener->onKeyReleased = [](EventKeyboard::KeyCode code, Event* e) {

		log("key code %d", code);
		switch (code)
		{
		case EventKeyboard::KeyCode::KEY_A:
			roles->changeState(0);
			roles->up = true;
			break;
		case EventKeyboard::KeyCode::KEY_D:
			roles->changeState(0);
			roles->up = true;
			break;
		case EventKeyboard::KeyCode::KEY_SPACE:
			roles->jump();
			break;
		default:
			break;
		}
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	
    return true;
}

void HelloWorld::update(float delta)
{
	if (KEY_DOWN(VK_LEFT) || KEY_DOWN('A'))
	{
		roles->changeState(1);
	}
	if (KEY_DOWN(VK_LEFT) || KEY_DOWN('D'))
	{
		roles->changeState(2);
	}
	this->role->start();
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
