#include "PolycodeView.h"
#include "Polycode.h"
#include "Polycode2DPhysics.h"


using namespace Polycode;

class spaceman{
public:
	spaceman(PolycodeView *view);
	~spaceman();
    
    bool Update();
    
private:
    Core *core;
};