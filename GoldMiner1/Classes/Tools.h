//
//  Tools.h
//  DVGoldMiner
//
//  Created by user on 13-5-28.
//
//

#ifndef __DVGoldMiner__Tools__
#define __DVGoldMiner__Tools__

#include <iostream>
#include "cocos2d.h"
#include "ItemUnit.h"
using namespace cocos2d;
class Tools
{
public:
    static bool iscollision(Sprite *sprite1, Sprite *sprite2);
    static Point getPointWithType(ItemKindType type,ItemSizeType sizeType);
};
#endif /* defined(__DVGoldMiner__Tools__) */
