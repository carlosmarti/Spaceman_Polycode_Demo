#include "Polycode.h"
#include "Polycode2DPhysics.h"
#include "Player.h"

class GameScene : public Polycode::PhysicsScene2D{

public:
	GameScene();
	~GameScene();

	void Update();
	void fixedUpdate();


private:
	Polycode::Core *core;
	Polycode::SceneEntityInstance *level;
	Polycode::SceneEntity *playerBody;
	vector< Polycode::SceneEntity *>platforms;
	vector<Polycode::SceneEntity *>shots;
	Polycode::PhysicsScene2DEntity *playerPhics;
	Polycode::SceneEntity *groundSensor;
	Player *player;
	double shotTimer;
	float moveDir;
	int shotIndex;
	vector<double> shotDirection;


};