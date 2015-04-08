//
//  Hook.cpp
//  DVGoldMiner
//
//  Created by user on 13-5-27.
//
//

#include "Hook.h"
Hook::Hook()
{
    Sprite::initWithFile("hook.png");
    isCatchItem = false;
}

void Hook::runRotateAction()
{
    this->setAnchorPoint(Point(0.5,1));
    
    //设置勾子旋转，2是旋转时间，90是旋转的角度。
    auto action1 = CCRotateTo::create(2, -90.0);
    auto action2 = CCRotateTo::create(2, 90.0);
    
    //得到对360度取模后的度数
    float rotate = this->getRotation();
    
    //把多个动作组合起来，让他们连续执行。
    Sequence *action3;
    if(rotate>0)
    {
        action3 = Sequence::create(action1, action2, NULL);
    }
    else
    {
        action3 = Sequence::create(action2, action1, NULL);
    }
    
    //让旋转这个动作一直执行
    auto repeat = CCRepeatForever::create(action3);
    this->runAction(repeat);
}

//勾子回到原来的地方
void Hook::runBack()
{
    auto winSize = Director::getInstance()->getWinSize();
    auto action4 = MoveTo::create(2, Point(winSize.width/2-2, winSize.height/2-20));
    //回到原来的位置后勾子继续旋转
    auto func = CallFunc::create(CC_CALLBACK_0(Hook::runRotateAction, this));
    auto seq = Sequence::create(action4, func, NULL);
    this->runAction(seq);
}

void Hook::runToPoint(Point point)
{
    this->stopAllActions();
    
    auto start =  this->getPosition();
    
    //三角形的勾股定理计算出勾子与点击点的距离
    float distance = sqrtf((start.x - point.x) * (start.x - point.x) +  (start.y - point.y) * (start.y - point.y));
    
    //设置勾子运动到点击点的所用的时间
    float time = distance * 0.01;
    auto actionTo = MoveTo::create(time, point);
    //勾子跑到点击点后再回到原来的点
    auto fun = CallFunc::create(CC_CALLBACK_0(Hook::runBack, this));
    auto seq = Sequence::create(actionTo, fun, NULL);
    this->runAction(seq);
}

void Hook::runTargetAction()
{
    float x;
    float y;
    //如果勾子的角度对360度取模后大于0
    if(this->getRotation() > 0)
    {
        //这个56.3度是tan值，画图就明白了。
        if(this->getRotation() <= 56.3)
        {
            y = 0.0;
            x = 240 - 160 * tan(this->getRotation() * 3.1415 / 180);
            
        }
        else
        {
            y = 160 - 240 / tan(this->getRotation() * 3.1415 / 180);
            x = 0.0;
        }
    }
    else if(this->getRotation() < 0)
    {
        if(this->getRotation() <= -56.3)
        {
            y = 160 + 240/tan(this->getRotation() * 3.1415 / 180);
            x = 480;
        }
        else
        {
            y = 0;
            x = 240-160*tan(this->getRotation()*3.1415/180);
        }
    }
    else if(this->getRotation() == 0)
    {
        x = 240;
        y = 160;
    }
    this->runToPoint(Point(x, y));
}

