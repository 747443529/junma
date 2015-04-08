//
//  ItemUnit1.h
//  DVGoldMiner
//
//  Created by user on 13-5-27.
//
//

#ifndef __DVGoldMiner__ItemUnit1__
#define __DVGoldMiner__ItemUnit1__

#include <iostream>
#include <iostream>
#include "cocos2d.h"

typedef enum
{
	Item_small = 0,
	Item_middle,
	Item_large,
}ItemSizeType;

typedef enum
{
    Item_gold = 0,
    Item_stone,
    Item_diamond,
    Item_secret,
}ItemKindType;


class ItemUnit:public cocos2d::Sprite
{
public:
    int weight;
    int score;
    //用来判断自己是否被勾子抓住
    bool isCatch;
    ItemUnit(ItemKindType spriteType, ItemSizeType spriteSize);
};

#endif /* defined(__DVGoldMiner__ItemUnit1__) */
