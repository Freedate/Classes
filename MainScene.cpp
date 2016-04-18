#include "MainScene.h"

USING_NS_CC;

Scene* Main::createScene()
{

	//auto scene = Scene::create();
	//auto layer = Main::create();
	//scene->addChild(layer);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vect gravity = Vect(0.0f, -300.0f);

	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(gravity);

	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	edgeNode->setPhysicsBody(body);
	scene->addChild(edgeNode);

	auto layer = Main::create();
	layer->setPhyWorld(scene->getPhysicsWorld());

	scene->addChild(layer);

	return scene;
}


bool Main::init()
{

	if (!Layer::init())
	{
		return false;
	}
	initGround();



	initPlayer();
	


	

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Main::onTouchBegan, this);
	//listener->onTouchMoved = CC_CALLBACK_2(Main::onTouchMoved, this);
	//listener->onTouchEnded = CC_CALLBACK_2(Main::onTouchEnded, this);
	//listener->onTouchCancelled = CC_CALLBACK_2(Main::onTouchCancelled, this);

	
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
	



	return true;
}

void Main::initPlayer() {
	playerspr = Sprite::create("../../Classes/res/Spr_Player_Idle.png");
	playerspr->setAnchorPoint(Point(0.0, 0.0));
	playerspr->setPosition(Point(100, 200));

	auto material1 = PhysicsMaterial(1.0f, 0.0f, 1.0f);
	auto material2 = PhysicsMaterial();

	auto body = PhysicsBody::createBox(Size(playerspr->getContentSize().width/2,playerspr->getContentSize().height), material1);
	body->setMass(50.0f);
	playerspr->setPhysicsBody(body);


	this->addChild(playerspr);
}
bool Main::onTouchBegan(Touch *touch, Event *unused_event) {
	CCLOG("onTouchBegan");

	auto jump = JumpBy::create(0.5, Point(0, 50), 50, 1);
	playerspr->runAction(jump);
	return true;
}

void Main::initGround() {
	auto groundspr = Sprite::create("../../Classes/res/Ground_0.png");
	groundspr->setAnchorPoint(Point(0.0, 0.0));
	groundspr->setPosition(Point(10, 10));

	auto material1 = PhysicsMaterial(1.0f, 0.0f, 1.0f);
	auto material2 = PhysicsMaterial();
	auto body = PhysicsBody::createBox(Size(groundspr->getContentSize().width, groundspr->getContentSize().height/4), material1);
	body->setMass(50.0f);
	groundspr->setPhysicsBody(body);
	this->addChild(groundspr);

}