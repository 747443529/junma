//
//  Miner.cpp
//  DVGoldMiner
//
//  Created by user on 13-5-27.
//
//

#include "Miner.h"
using namespace cocos2d;
Miner::Miner()
{
    Sprite::initWithFile("miner.png");
}

//开始旷工的帧动画运动
void Miner::runStayguyAction()
{
    this->stopAllActions();
    
    //用来存放每一帧图片的容器。
    Vector<SpriteFrame *> vector;
    
    //获取plist文件中有多少个图片
    auto tempDic = __Dictionary::createWithContentsOfFile("minerAction.plist");
    auto dic = (__Dictionary *)tempDic->objectForKey("frames");
    int num = dic->allKeys()->count();
    
    for(int i = 1; i <= num; ++i)
    {
        //取出第一帧图片，放到容器中。
        SpriteFrame *frame = NULL;
        if (i < 10) {
            frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(__String::createWithFormat("miner_070%d.png", i)->getCString());
        } else {
            frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(__String::createWithFormat("miner_07%d.png", i)->getCString());
        }
    
        vector.pushBack(frame);
    }
    
    //用容器中的帧图片来创建一个动画对象。第二个参数表示这个动画执行多长时间。第三个参数表示这个动画执行了多少次。
    auto animation = Animation::createWithSpriteFrames(vector, 0.2, 1);
    
    auto plitAnimate = Animate::create(animation);
    
    this->runAction(RepeatForever::create(RepeatForever::create(plitAnimate)));
}
