#include "Player.h"

using namespace Polycode;

Player::Player(SceneEntity *playerBody,PhysicsScene2DEntity *phcsBody)
{
	core = Services()->getCore();
	player = playerBody;
	physicsBody = phcsBody;

	playerTop = (SceneSprite *)player->getEntityById("top", true);
	playerButtom = (SceneSprite *)player->getEntityById("legs", true);
	

	playerTop->backfaceCulled = false;
	playerButtom->backfaceCulled = false;
	touchingGround = false;

	topSinValue = 0.0;
	jumpLeft = 1;
	shotAngle = 0.0;
	moveDir = 0.0;

	jumpSound = new Sound("Resources/sounds/jump.ogg");
	shotSound = new Sound("Resources/sounds/shot.ogg");

	core->getInput()->addEventListener(this, InputEvent::EVENT_KEYDOWN);
}

Player::~Player()
{

}

void Player::Update()
{
	topSinValue += core->getElapsed() * 20.0;
	playerTop->setPositionY(0.06090 + sin(topSinValue) * 0.025);

	moveDir = 0.0;
	if (Services()->getInput()->getKeyState(KEY_LEFT))
	{
		moveDir -= 1;
		player->setScaleX(-1.0);
	}
	else if (Services()->getInput()->getKeyState(KEY_RIGHT))
	{
		moveDir += 1;
		player->setScaleX(1);
	}

	if (Services()->getInput()->getKeyState(KEY_UP))
	{
		playerTop->setRoll(45);
		if (player->getScale().x > 0.0)
		{
			shotAngle = 45;
		}
		else
		{
			shotAngle = 135;
		}
	}
	else if (Services()->getInput()->getKeyState(KEY_DOWN))
	{
		playerTop->setRoll(-45);
		if (player->getScale().x > 0.0)
		{
			shotAngle = -45;
		}
		else
		{
			shotAngle = -135;
		}
	}
	else
	{
		playerTop->setRoll(0);
		if (player->getScale().x == 0.0)
		{
			shotAngle = 0;
		}
		else
		{
			shotAngle = 180;
		}
	}

	if (touchingGround)
	{
		if (moveDir == 0.0)
		{
			playerButtom->setSpriteStateByName("idle", 0, false);
		}
		else
		{
			playerButtom->setSpriteStateByName("running", 0, false);
		}
	}

	physicsBody->setVelocityX(moveDir * 5.0);
}

void Player::fixedUpdate()
{
	if (player->getPosition().y < -8.0)
	{
		physicsBody->setTransform(Vector2(player->getPosition().x,8.0), 0.0);
	}

	if (player->getPosition().x < -12.0)
	{
		physicsBody->setTransform(Vector2(12, player->getPosition().y), 0.0);
	}

	if (player->getPosition().x > 12.0)
	{
		physicsBody->setTransform(Vector2(-12, player->getPosition().y), 0.0);
	}
}

void Player::handleEvent(Event *ev)
{
	if (ev->getDispatcher() == Services()->getInput())
	{
		InputEvent *inputEv = (InputEvent *)ev;
		switch (ev->getEventCode())
		{
		case InputEvent::EVENT_KEYDOWN:
			switch (inputEv->keyCode())
			{
			case KEY_z:
				physicsBody->setVelocityY(0.0);
				physicsBody->applyImpulse(0.0, 140.0);
				jumpLeft -= 1;
				jumpSound->Play();
				break;
			}
			break;
		}
	}
}

void Player::playerTouchingGround(bool touching)
{
	if (touching)
	{
		touchingGround = true;
		jumpLeft = 1;
	}
	else
	{
		touchingGround = false;
		playerButtom->setSpriteStateByName("jumping", 0, false);
	}
}

double Player::shot(SceneEntity *shot)
{
	shot->setPosition(player->getPosition().x + (0.25 * cos(shotAngle * 0.0174532925)) - 0.1, player->getPosition().y + (0.25 * sin(shotAngle * 0.0174532925)) + 0.3, player->getPosition().z);
	shotSound->Play();
	return shotAngle;
}