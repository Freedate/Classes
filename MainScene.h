#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class Main : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void initPlayer();
	void initGround();
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);

	Sprite* playerspr;
	Sprite* groundspr0;
	Sprite* groundspr1;
	Sprite* groundspr2;

	CREATE_FUNC(Main);

	//PhysicsWorld* m_world;
	//void setPhyWorld(PhysicsWorld* world) { m_world = world; }




};

#endif // __HELLOWORLD_SCENE_H__
