//
//  ShopLayer.cpp
//  GoldMiner
//
//  Created by wangze on 14-6-16.
//
//

#include "ShopLayer.h"
#include "Tradeswoman.h"
#include "GameLayer.h"

//引用别的文件中的全局变量, 一定要加上extern 声明一下
extern int Level;
extern int ToTalLevel;
extern int TotalSocre;

Scene * ShopLayer::scene()
{
    auto scene = Scene::create();
    auto layer = ShopLayer::create();
    scene->addChild(layer);
    return scene;
}

bool ShopLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    //背景
    Size winSize = Director::getInstance()->getWinSize();
    auto bgSprite = Sprite::create("shopBack.png");
    bgSprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
    this->addChild(bgSprite);
    
    //桌子
    auto table = Sprite::create("tableImage.png");
    table->setPosition(Point(240, 65));
    this->addChild(table);
    
    //女售货员
    woman = new Tradeswoman();
    woman->setPosition(Point(100, 200));
    addChild(woman);
    //新游戏
    if (Level == 0) {
        auto item1 = MenuItemFont::create("新游戏", CC_CALLBACK_0(ShopLayer::againGame, this));
        item1->setColor(Color3B(255, 0, 0));
        auto menu = Menu::create(item1, NULL);
        menu->setPosition(Point(400, 30));
        addChild(menu);
        
        woman->action1();
    }
    else if (Level < ToTalLevel) { //下一关
        woman->action2();
        
        auto next = MenuItemImage::create("shopArrow.png", "shopArrow.png", CC_CALLBACK_0(ShopLayer::goNext, this));
        auto menu = Menu::create(next, NULL);
        menu->setPosition(Point(425, 30));
        this->addChild(menu);
    }
    else { //通关
        woman->action3();
        
        auto item1 = MenuItemFont::create("恭喜通关");
        item1->setColor(Color3B(255, 0, 0));
        auto item2 = MenuItemFont::create("新游戏", CC_CALLBACK_0(ShopLayer::againGame, this));
        item2->setColor(Color3B(255, 0, 0));
        
        auto menu = Menu::create(item1, item2, NULL);
        menu->setPosition(Point(400, 60));
        menu->alignItemsVerticallyWithPadding(20);
        addChild(menu);
    }
    
    
    return true;
}

void ShopLayer::againGame()
{
    //修改全局变量的值。
    Level = 0;
    TotalSocre = 0;
    
    //进入游戏
    Director::getInstance()->replaceScene(TransitionJumpZoom::create(1, GameLayer::scene()));
}


void ShopLayer::goNext()
{
    Director::getInstance()->replaceScene(TransitionJumpZoom::create(1, GameLayer::scene()));
}