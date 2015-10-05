#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
   // Vector<int> disableShadowTags;
    _backgroundElements = InfiniteParallaxNode::create();
    unsigned int rocksQuantity = 7;
    auto ground= Sprite::create("ground.png");
    ground->setPosition(Vect(visibleSize.width/2,visibleSize.height/2));
    ground->setAnchorPoint(Vect(0,0));
    //addChild(ground);
    for(unsigned int i = 0; i < rocksQuantity; i++)
    {
        // Create a sprite with rock texture
        auto rock = Sprite::create("rock.png");
        rock->setAnchorPoint(Point::ZERO);
        // Set scale factor as a random value from [0.8, 1.2] interval
        rock->setScale(random(0.6, 0.75));
        rock->setTag(1000 + i);
        if(i==1)rock->setTag(1);
        _backgroundElements->addChild(rock,
                                      // Set random z-index from [-10,-6]
                                      i,
                                      // Set ration (rocks moves slow)
                                      Point(0.5, 0.5),
                                      // Set position with random component
                                      Point(10*i,ground->getContentSize().height +20));
    }
   // ground->addChild(_backgroundElements);
    addChild(_backgroundElements,1);
    auto arr= _backgroundElements->getParallaxArray();
    for(int i=0;i<arr->num;i++){
        auto var = (PointObject*)arr->arr[i];
        auto move = MoveTo::create(10, Vect(400,100));
        var->getChild()->runAction(move);
    }

    //spr->runAction(move);
    //sp->getChild()->setVertexZ(100);
    //schedule(schedule_selector(HelloWorld::update));
    return true;
}
void HelloWorld::update(float dt){
  
   
}