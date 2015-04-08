//
//  GameLayer.h
//  DVGoldMiner
//
//  Created by user on 13-5-29.
//
//

#ifndef __DVGoldMiner__GameLayer__
#define __DVGoldMiner__GameLayer__

#include <iostream>
#include "cocos2d.h"
#include "ItemUnit.h"

class Hook; //钩子
class Miner;//矿工
class ItemUnit;//物品

using namespace cocos2d;
class GameLayer:public Layer
{
public:
    Hook *hook;
    Miner *miner;
    ItemUnit *itemUnit;
    
    __Array *itemUtilArray;
    
    CustomCommand _customCommand;
    
public:
    Sprite *alarmClock;
    Label *alarmClockLabel;
    
    Sprite *levelOfSprite;
    Label *levelOfSpriteLabel;
    
    Sprite *needTotalScoreSrpite;
    Label *needTotalScoreSrpiteLabel;
    
    Sprite *currentScoreSprite;
    Label *currentScoreSpriteLabel;
    
public:
    //剩余时间
    int residueTime;
    
    //用来判断闹钟是否正在摇摆
    bool alarmRun;
    
public:
    ~GameLayer();
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(GameLayer);
    
public:
    void addItem();
    void addItemWithType(ItemKindType type, int count);
    void addSpriteLabel();
    void checkCollision(float f);
    void deleteItemUnit(Node* sender,ItemUnit *item);
    void itemUnitFollowHook(float f);
    void timeResidue(float f);
    
public:
    void draw(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
    
};

#endif
