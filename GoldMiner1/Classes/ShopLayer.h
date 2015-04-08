//
//  ShopLayer.h
//  GoldMiner
//
//  Created by wangze on 14-6-16.
//
//

#ifndef __GoldMiner__ShopLayer__
#define __GoldMiner__ShopLayer__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

class Tradeswoman;

class ShopLayer : public Layer
{
public:
    static Scene *scene();
    virtual bool init();
    CREATE_FUNC(ShopLayer);
    
    Tradeswoman *woman;
    
public:
    void goNext();
    void againGame();
};

#endif /* defined(__GoldMiner__ShopLayer__) */
