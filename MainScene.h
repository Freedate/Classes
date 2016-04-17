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
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);

	Sprite* playerspr;

	CREATE_FUNC(Main);

	PhysicsWorld* m_world;
	void setPhyWorld(PhysicsWorld* world) { m_world = world; }

	void addNewSpriteAtPosition(Point p);



};

#endif // __HELLOWORLD_SCENE_H__
