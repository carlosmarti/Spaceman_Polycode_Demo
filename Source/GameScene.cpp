#include "GameScene.h"

using namespace Polycode;

GameScene::GameScene(){

	core = Services()->getCore();
	getActiveCamera()->setOrthoSize(0.0, 14);
	this->worldScale = 1.0;
	setGravity(Vector2(0.0, -30));
	level = new SceneEntityInstance(this,"Resources/entities/level.entity");
	platforms = level->getEntitiesByTag("platform", false);
	for (int i = 0; i < platforms.size(); i++)
	{
		trackPhysicsChild(platforms[i], PhysicsScene2DEntity::ENTITY_RECT, true, 2.0, 1, 0.0, false, false);
	}
	playerBody = (SceneEntity *)level->getEntityById("player", true);
	playerPhics = trackPhysicsChild(playerBody, PhysicsScene2DEntity::ENTITY_TRIPLE_CIRCLE, false, 0, 10, 0, false, true, -1);
	groundSensor = (SceneEntity *)playerBody->getEntityById("groundSensor", true);
	addChild(level);

	//player = new Player(playerBody, playerPhics);

	shotTimer = 0.0;
	shots = level->getEntitiesByTag("shot", false);
	for (int i = 0; i < shots.size(); i++)
	{
		trackCollisionChild(shots[i], PhysicsScene2DEntity::ENTITY_RECT, -1);
	}
	shotIndex = 0;
}

GameScene::~GameScene(){


}

void GameScene::Update(){

	moveDir = 0.0;
	if (Services()->getInput()->getKeyState(KEY_LEFT))
	{
		playerBody->setScaleX(-1.0);
		moveDir -= 1.0;
	}

	if (Services()->getInput()->getKeyState(KEY_RIGHT))
	{
		playerBody->setScaleX(1.0);
		moveDir += 1.0;
	}

	playerPhics->setVelocityX(moveDir * 5.0);
	/*shotTimer += core->getElapsed();
	if (Services()->getInput()->getKeyState(KEY_x))
	{
		if (shotTimer > 0.30)
		{
			 player->shot(shots[shotIndex]);
			shotIndex += 1;
			if (shotIndex > shots.size())
			{
				shotIndex = 1;
			}
			shotTimer = 0.0;
		}
	}
	if (isEntityColliding(groundSensor))
	{
		OutputDebugStringW(L"touching ground.\n");
		player->playerTouchingGround(true);
	}
	else
	{
		OutputDebugStringW(L"not touching ground\n");
	}
	
	player->Update();*/
}

void GameScene::fixedUpdate()
{
	//Number delta = core->getFixedTimestep();
	//player->fixedUpdate();
	
	/*shots[shotIndex]->setRoll(shotDirection[shotIndex]);
	shots[shotIndex]->Translate(delta * 18.0 * cos(shotDirection[shotIndex] * 0.0174532925), delta * 18.0 * sin(shotDirection[shotIndex] * 0.174532925), 0.0);*/
	
}

