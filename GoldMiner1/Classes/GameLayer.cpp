//
//  GameLayer.cpp
//  DVGoldMiner
//
//  Created by user on 13-5-29.
//
//

#include "GameLayer.h"
#include "ShopLayer.h"
#include "Miner.h"
#include "Hook.h"
#include "Tools.h"
#include "Data.h"

using namespace cocos2d;

GameLayer::~GameLayer()
{
    miner->release();
    hook->release();
}

Scene * GameLayer::scene()
{
    auto scene = Scene::create();
    auto layer = GameLayer::create();
    scene->addChild(layer);
    return scene;
}

bool GameLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    auto winSize = Director::getInstance()->getWinSize();
    char temp[50];
    sprintf(temp, "mineBG%d.png", Level + 1);
    
    //选择是哪一关的背景
    auto sprite = Sprite::create(temp);
    sprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
    addChild(sprite);
    sprite->setZOrder(-1);
    
    //矿工
    miner = new Miner();
    miner->setPosition(Point(winSize.width/2, winSize.height/2));
    addChild(miner);
    
    //加上钩子 线的用一个函数来更新每次都进行重新绘制
    hook = new Hook();
    hook->runRotateAction();
    hook->setPosition(Point(winSize.width / 2 - 2, winSize.height / 2 - 20));
    addChild(hook);
    
    //加上石头，金子等物品
    itemUtilArray = __Array::create();
    itemUtilArray->retain();
    this->addItem();
    
    //添加闹钟
    alarmClock = Sprite::create("clockPlate.png");
    alarmClock->setPosition(Point(380, 260));
    addChild(alarmClock);
    
    //添加上金钱什么的在上面
    addSpriteLabel();
    
    //启动检测碰撞的函数
    this->schedule(schedule_selector(GameLayer::checkCollision), 0.1);
    
    //让物品跟着勾子一起运动
    this->schedule(schedule_selector(GameLayer::itemUnitFollowHook), 0.1);
    
    //让时间一秒一秒减少
    residueTime = TotalTime[Level];
    this->schedule(schedule_selector(GameLayer::timeResidue), 1);
    
    //3.0中添加点击响应事件
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = [](Touch *pTouch, Event *pEvent){
        return true;
    };
    
    touchListener->onTouchEnded = [this](Touch *pTouch, Event *pEvent){
        auto p = hook->getPosition();
        log("%f",p.x);
        log("%f",p.y);
        if(p.x == 238 && p.y == 140)
        {
            hook->runTargetAction();
            miner->runStayguyAction();
        }
    };

    dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}

void GameLayer::addItem()
{
    //加石头
    int count = ItemStoneNumber[Level];
    this->addItemWithType(Item_stone, count);
    
    //加黄金
    count = ItemGoldNumber[Level];
    this->addItemWithType(Item_gold, count);
    
    //加钻石
    count = ItemDiamondNumber[Level];
    this->addItemWithType(Item_diamond, count);
    
    //加神秘物品
    count = ItemSecretNumber[Level];
    this->addItemWithType(Item_secret, count);
}
//根据不同的类型加入图层中不同的物品。一个物品是一个对象。
void GameLayer::addItemWithType(ItemKindType type, int count)
{
    for(int i = 0; i < count; i++)
    {
        int k = rand() % 3;
        ItemUnit *item;
        switch (k)
        {
            case 0:
                item = new ItemUnit(type, Item_small);
                item->setPosition(Tools::getPointWithType(type, Item_small));
                break;
            case 1:
                item = new ItemUnit(type, Item_middle);
                item->setPosition(Tools::getPointWithType(type, Item_middle));
                break;
            case 2:
                item = new ItemUnit(type,Item_large);
                item->setPosition(Tools::getPointWithType(type, Item_large));
                break;
            default:
                break;
        }
        this->addChild(item);
        itemUtilArray->addObject(item);
    }
}

void GameLayer::addSpriteLabel()
{
    char temp[50];
    //用来显示倒计时时间的label
    sprintf(temp, "%d", TotalTime[Level]);
    alarmClockLabel = Label::createWithSystemFont(temp, "Zapfino", 13);
    alarmClockLabel->setPosition(Point(420, 250));
    alarmClockLabel->setColor(Color3B(255, 0, 0));
    this->addChild(alarmClockLabel);
    
    //添加小人精灵，用来标示当前是第几关
    levelOfSprite = Sprite::create("miner_0707.png");
    levelOfSprite->setPosition(Point(380, 300));
    this->addChild(levelOfSprite);
    
    //用来显第几关的label
    sprintf(temp, "%d", Level + 1);
    levelOfSpriteLabel = Label::createWithSystemFont(temp, "Zapfino", 13);
    levelOfSpriteLabel->setPosition(Point(420, 290));
    levelOfSpriteLabel->setColor(Color3B(0, 0, 255));
    this->addChild(levelOfSpriteLabel);
    
    //添加精灵用来显示得了多少金币
    needTotalScoreSrpite = Sprite::create("rmbImage.png");
    needTotalScoreSrpite->setPosition(Point(50, 255));
    this->addChild(needTotalScoreSrpite);
    
    //用来显示得了多少金币的label
    sprintf(temp, "%d", TotalSocre);
    needTotalScoreSrpiteLabel = Label::createWithSystemFont(temp, "Zapfino", 13);
    needTotalScoreSrpiteLabel->setPosition(Point(110, 250));
    needTotalScoreSrpiteLabel->setColor(Color3B(0, 0, 255));
    this->addChild(needTotalScoreSrpiteLabel);
    
    //添加精灵用来显示总数
    currentScoreSprite = Sprite::create("Gold.png");
    currentScoreSprite->setPosition(Point(50, 290));
    this->addChild(currentScoreSprite);
    
    //用来显示总数的label
    sprintf(temp, "%d", NeedTotalScore[Level]);
    currentScoreSpriteLabel = Label::createWithSystemFont(temp, "Zapfino", 13);
    currentScoreSpriteLabel->setPosition(Point(110, 290));
    currentScoreSpriteLabel->setColor(Color3B(0, 0, 255));
    this->addChild(currentScoreSpriteLabel);
}

//碰撞检测
void GameLayer::checkCollision(float f)
{
    Size winSize = Director::getInstance()->getWinSize();
    
    for(int i = 0; i < itemUtilArray->count(); i++)
    {
        ItemUnit *item = (ItemUnit *)itemUtilArray->getObjectAtIndex(i);
        if(Tools::iscollision(item, hook) && !item->isCatch && !hook->isCatchItem)
        {
            //改变物体为被抓住状态
            item->isCatch = true;
            hook->isCatchItem = true;
            
            hook->stopAllActions();
            
            Point start = item->getPosition();
            Point point = hook->getPosition();
            float distance = sqrtf((start.x - point.x) * (start.x - point.x) +  (start.y - point.y) * (start.y - point.y));
            
            float weight = item->weight;
            float time = weight / distance * 3;
            
            auto moveTo = MoveTo::create(time, Point(winSize.width / 2 - 2, winSize.height / 2 - 20));
            
            
            CallFuncN  *funcND = CallFuncN::create( CC_CALLBACK_1(GameLayer::deleteItemUnit, this, item));
            Sequence *seq = Sequence::create(moveTo, funcND, NULL);
            hook->runAction(seq);
            
            this->itemUnit = item;
        }
    }
}

void GameLayer::itemUnitFollowHook(float f)
{
    if(itemUnit)
    {
        itemUnit->setRotation(hook->getRotation());
        itemUnit->setAnchorPoint(Point(0.5, 1));
        hook->setAnchorPoint(Point(0.5, 0.7));
        itemUnit->setPosition(hook->getPosition());
        hook->setAnchorPoint(Point(0.5, 1));
    }
}

void GameLayer::deleteItemUnit(Node* sender,ItemUnit *item)
{
    hook->runRotateAction();
    item->removeFromParent();
    miner->stopAllActions();
    itemUtilArray->removeObject(item);
    delete item;
    itemUnit = NULL;
    
    //抓取动作结束后勾子变为原来的未抓东西状态
    hook->isCatchItem = false;
    
    TotalSocre += item->score;
    char t[50];
    sprintf(t, "%d", TotalSocre);
    needTotalScoreSrpiteLabel->setString(t);
}

void GameLayer::timeResidue(float f)
{
    residueTime--;
    char time[50];
    sprintf(time, "%d", residueTime);
    alarmClockLabel->setString(time);
    
    if(residueTime < 10 && !alarmRun)
    {
        alarmRun = true;
        //闹钟摇摆
        auto rotateTo = RotateTo::create(0.1, 10);
        auto rotateTo1 = RotateTo::create(0.1, -10);
        auto seq = Sequence::create(rotateTo, rotateTo1, NULL);
        alarmClock->runAction(RepeatForever::create(seq));
    }
    
    if (residueTime == 0) {
        //胜利->进入商店
        if(TotalSocre >= NeedTotalScore[Level])
        {
            Level++;
        } else {
            Level = 0;
        }
        Director::getInstance()->replaceScene(TransitionSlideInR::create(1, ShopLayer::scene()));
    }
}

//draw函数会自动执行
void GameLayer::draw(Renderer *renderer, const kmMat4& transform, bool transformUpdated)
{
    _customCommand.init(_globalZOrder);
    
    _customCommand.func = [this](){
        auto winSize = Director::getInstance()->getWinSize();
        DrawPrimitives::setDrawColor4B(255, 0, 0, 255);
        glLineWidth(5.0f);
        DrawPrimitives::drawLine(Point(winSize.width / 2 - 2, winSize.height / 2 - 20), hook->getPosition());
    };

    renderer->addCommand(&_customCommand);
}

