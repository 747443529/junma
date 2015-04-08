//
//  Tradeswoman.cpp
//  DVGoldMiner
//
//  Created by user on 13-5-29.
//
//

#include "Tradeswoman.h"
Tradeswoman::Tradeswoman()
{
    Sprite::initWithSpriteFrameName("npc_2007.png");
}

void Tradeswoman::action1()
{
    stopAllActions();
    
    //用来存放每一帧图片的容器。
    Vector<SpriteFrame *> vector;
    
    char name[20];
    for(int i = 1; i < 12; ++i)
    {
        if(i < 10)
        {
            sprintf(name, "npc_100%d.png",i);
        }
        else
        {
            sprintf(name, "npc_10%d.png",i);
        }
        //取出第一帧图片，放到容器中。
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
        vector.pushBack(frame);
    }
    
    //用容器中的帧图片来创建一个动画对象。第二个参数表示这个动画执行多长时间。第三个参数表示这个动画执行了多少次。
    auto animation = Animation::createWithSpriteFrames(vector, 0.2, 7);
    this->runAction(RepeatForever::create(Animate::create(animation)));
}

void Tradeswoman::action2()
{
    stopAllActions();
    
    //用来存放每一帧图片的容器。
    Vector<SpriteFrame *> vector;
    
    char name[20];
    for(int i = 2; i <= 10; i++)
    {
        if(i < 10)
        {
            sprintf(name, "npc_200%d.png",i);
        }
        else
        {
            sprintf(name, "npc_20%d.png",i);
        }
        //取出第一帧图片，放到容器中。
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
        vector.pushBack(frame);
    }
    
    //用容器中的帧图片来创建一个动画对象。第二个参数表示这个动画执行多长时间。第三个参数表示这个动画执行了多少次。
    auto animation = Animation::createWithSpriteFrames(vector, 0.2, 7);
    this->runAction(RepeatForever::create(Animate::create(animation)));
}

void Tradeswoman::action3()
{
    stopAllActions();
    
    //用来存放每一帧图片的容器。
    Vector<SpriteFrame *> vector;
    
    char name[20];
    for(int i = 2; i <= 10; i++)
    {
        if(i < 10)
        {
            sprintf(name, "npc_300%d.png",i);
        }
        else
        {
            sprintf(name, "npc_30%d.png",i);
        }
        //取出第一帧图片，放到容器中。
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
        vector.pushBack(frame);
    }
    
    //用容器中的帧图片来创建一个动画对象。第二个参数表示这个动画执行多长时间。第三个参数表示这个动画执行了多少次。
    auto animation = Animation::createWithSpriteFrames(vector, 0.2, 7);
    this->runAction(RepeatForever::create(Animate::create(animation)));
 }