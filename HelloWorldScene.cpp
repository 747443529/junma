#include "HelloWorldScene.h"

USING_NS_CC;

bool isTouch=false;
int pressTime=0;
int touchCounts=0;

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
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
    auto eventDispatatche=Director::getInstance()->getEventDispatcher();
    auto touchListener=EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan=CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    touchListener->onTouchMoved=CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    touchListener->onTouchEnded=CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    touchListener->onTouchCancelled=CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
    eventDispatatche->addEventListenerWithSceneGraphPriority(touchListener, this);
    longProgress=false;
    
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
   
    return;
#endif

    Director::getInstance()->end();
     log("滚蛋了");

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

long long HelloWorld::getCurrentTime()
{
    struct timeval tm;
    gettimeofday(&tm, NULL);
    return (double)(tm.tv_sec*1000+tm.tv_usec/1000);
}
bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
    isTouch=true;
    startTime=getCurrentTime();
    this->schedule(schedule_selector(HelloWorld::updateLongProgress),1);
    return true;
    
}
void HelloWorld::onTouchMoved(Touch *touch, Event *unused_event)
{
    
}
void HelloWorld::onTouchEnded(Touch *touch, Event *unused_event)
{
    isTouch=false;
    pressTime=0;
    this->unschedule(schedule_selector(HelloWorld::updateLongProgress));
    if (longProgress) {
        touchCounts=0;
        longProgress=false;
        return;
    }
    long long endTime=getCurrentTime();
    timeDis=endTime-startTime;
    if (touchCounts==0)
    {
        this->scheduleOnce(schedule_selector(HelloWorld::updateSingleDelay),0.25);
        touchCounts++;
       
        
    }
    else if(touchCounts==1)
    {
        
        //this->scheduleOnce(schedule_selector(HelloWorld::updateDoubleDelay), 0.25);
        doubleClick();
        touchCounts=0;
      
    }
}
void HelloWorld::onTouchCancelled(Touch *touch, Event *unused_event)
{
    
}

void HelloWorld::updateSingleDelay(float ft)
{
    if ((touchCounts=1))
    {
        singleClick();
        touchCounts=0;
    }
}
void HelloWorld::updateDoubleDelay(float ft)
{
    if (touchCounts==2)
    {
        doubleClick();
        touchCounts=0;
    }
}
void HelloWorld::updateLongProgress(float ft)
{
    if (isTouch)
    {
        pressTime++;
        if (pressTime==1 && timeDis>2)
        {
            longProgress=true;
            longPressed();
        }
    }
    else
    {
        pressTime=0;
    }
}
void HelloWorld::singleClick()//单击
{
    log("单击");
}
void HelloWorld::doubleClick()//双击
{
    log("双击");
}
void HelloWorld::longPressed()//长按
{
    log("长按");
}
