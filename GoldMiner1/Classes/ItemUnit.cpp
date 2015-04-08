//
//  ItemUnit1.cpp
//  DVGoldMiner
//
//  Created by user on 13-5-27.
//
//

#include "ItemUnit.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

ItemUnit::ItemUnit(ItemKindType spriteType, ItemSizeType spriteSize)
{
    //初始值是自己没有被勾子抓住
    this->isCatch = false;
    
    switch (spriteType)
    {
        case Item_stone:
        {
            switch (spriteSize)
            {
                case Item_small:
                {
                    this->initWithFile("stone_small.png");
                    this->score = 10;
                    this->weight = 10;
                    break;
                }
                case Item_middle:
                {
                    this->initWithFile("stone_middle.png");
                    this->score = 20;
                    this->weight = 20;
                    break;
                }
                case Item_large:
                {
                    this->initWithFile("stone_large.png");
                    this->score = 40;
                    this->weight = 40;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case Item_gold:
        {
            switch (spriteSize)
            {
                case Item_small:
                {
                    this->initWithFile("gold_small.png");
                    this->score = 100;
                    this->weight = 10;
                    break;
                }
                case Item_middle:
                {
                    this->initWithFile("gold_middle.png");
                    this->score = 200;
                    this->weight = 20;
                    break;
                }
                case Item_large:
                {
                    this->initWithFile("gold_large.png");
                    this->score = 400;
                    this->weight = 40;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case Item_diamond:
        {
            switch (spriteSize)
            {
                case Item_small:
                {
                    this->initWithFile("diamond_small.png");
                    this->score = 50;
                    this->weight = 5;
                    break;
                }
                case Item_middle:
                {
                    this->initWithFile("diamond_middle.png");
                    this->score = 100;
                    this->weight = 10;
                    break;
                }
                case Item_large:
                {
                    this->initWithFile("diamond_large.png");
                    this->score = 400;
                    this->weight = 20;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case Item_secret:
        {
            switch (spriteSize)
            {
                case Item_small:
                {
                    this->initWithFile("secret_small.png");
                    this->score = 100;
                    this->weight = 5;
                    break;
                }
                case Item_middle:
                {
                    this->initWithFile("secret_middle.png");
                    this->score = 200;
                    this->weight = 10;
                    break;
                }
                case Item_large:
                {
                    this->initWithFile("secret_large.png");
                    this->score = 300;
                    this->weight = 15;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}
