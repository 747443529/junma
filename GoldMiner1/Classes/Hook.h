//
//  Hook.h
//  DVGoldMiner
//
//  Created by user on 13-5-27.
//
//

#ifndef __DVGoldMiner__Hook__
#define __DVGoldMiner__Hook__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

class Hook:public Sprite
{
public:
    Hook();
    bool isCatchItem;
    void runRotateAction();
    void runTargetAction();
    void runToPoint(Point point);
    void runBack();
};
#endif
/* defined(__DVGoldMiner__Hook__) */
