//
//  MainLayer.cpp
//  DVGoldMiner
//
//  Created by user on 13-5-27.
//
//

#include "MainLayer.h"
#include "GameLayer.h"
#include "ShopLayer.h"
#include "cocos2d.h"

using namespace cocos2d;

Scene * MainLayer::scene()
{
    auto scene = Scene::create();
    MainLayer *layer = MainLayer::create();
    scene->addChild(layer);
    return scene;
}

bool MainLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    auto winSize = Director::getInstance()->getWinSize();
    
    auto sprite = CCSprite::create("MainMenu.png");
    sprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
    this->addChild(sprite);
    
    auto playItem = CCMenuItemImage::create("PlayMenu.png", "playMenu.png");
    playItem->setCallback(CC_CALLBACK_1(MainLayer::goGameLayer, this));
    
    auto menu = Menu::createWithItem(playItem);
    menu->setPosition(Point(130, 225));
    this->addChild(menu);
    
    return true;
}


void MainLayer::goGameLayer(Ref *pSender)
{
    Director::getInstance()->replaceScene(ShopLayer::scene());
}