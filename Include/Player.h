#include <Polycode.h>
#include "Polycode2DPhysics.h"

class Player : public Polycode::Entity{

public:
	Player(Polycode::SceneEntity *,Polycode::PhysicsScene2DEntity *);
	~Player();

	void Update();
	void fixedUpdate();
	void handleEvent(Polycode::Event *);
	void playerTouchingGround(bool);
	double shot(Polycode::SceneEntity *);

private:
	Polycode::Core *core;
	Polycode::SceneEntity *player;
	Polycode::SceneSprite *playerTop;
	Polycode::SceneSprite *playerButtom;
	Polycode::PhysicsScene2DEntity *physicsBody;

	double topSinValue;
	bool touchingGround;
	int jumpLeft;
	double shotAngle;
	double moveDir;

	Polycode::Sound *shotSound;
	Polycode::Sound *jumpSound;

};