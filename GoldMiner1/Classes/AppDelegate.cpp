#include "AppDelegate.h"
#include "MainLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
    
    //屏幕适配
    director->getOpenGLView()->setDesignResolutionSize(480, 320, ResolutionPolicy::EXACT_FIT);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("backMusic.mp3", true);
    
    
    //加载资源,只有加载了资源后才能访问到里面的png内容。添加精灵缓冲帧
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("minerAction.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shop_npc.plist");
    auto scene = MainLayer::scene();

    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
