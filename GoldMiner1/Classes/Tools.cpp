//
//  Tools.cpp
//  DVGoldMiner
//
//  Created by user on 13-5-28.
//
//

#include "Tools.h"

bool Tools::iscollision(Sprite *sprite1, Sprite *sprite2)
{
    auto rect1 = sprite1->boundingBox();
    auto rect2 = sprite2->boundingBox();
    
    return rect1.intersectsRect(rect2);
}

Point Tools::getPointWithType(ItemKindType type, ItemSizeType sizeType)
{
    //要返回的随机点
    Point p;
    
    //要返回随机点的x,y坐标用随机数来取值
    int x = arc4random() * 10;
    int y = arc4random() * 10;
    
    switch (type)
    {
        case Item_secret:
            x %= 480;
            y %= 80;
            break;
            
        case Item_gold:
            switch (sizeType)
        {
            case Item_middle:
                x %= 480;
                y %= 100;
                break;
            case Item_large:
                x %= 480;
                y %= 80;
                break;
            default:
                break;
        }
            break;
            
        case Item_stone:
            x %= 480;
            y %= 100;
            break;
        default:
            break;
    }
    
    p.x = fabsf(x);
    p.y = fabsf(y);
    
    return p;
}