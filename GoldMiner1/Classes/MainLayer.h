//
//  MainLayer.h
//  DVGoldMiner
//
//  Created by user on 13-5-27.
//
//

#ifndef __DVGoldMiner__MainLayer__
#define __DVGoldMiner__MainLayer__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
using namespace cocos2d;
class MainLayer:public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(MainLayer);
    static cocos2d::Scene* scene();
    
    void goGameLayer(Ref *pSender);
    
public:
    //MenuItemToggle *musicItemToggle;
};

#endif 
/* defined(__DVGoldMiner__MainLayer__) */
