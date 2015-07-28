#include "spaceman.h"
#include "GameScene.h"

spaceman::spaceman(PolycodeView *view) {
	core = new POLYCODE_CORE(view, 1280,720,false,true, 0, 0,60);	  
	CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	// Write your code here
	GameScene *scene = new GameScene();

}
spaceman::~spaceman() {
    
}

bool spaceman::Update() {
	return core->updateAndRender();
}