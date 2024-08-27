#include "CommandLevel1p2True.h"
#include "MainMenu.h"
using namespace Scenes;

CommandLevel1p2True::CommandLevel1p2True(Menu* _bound):Command(_bound){}

void CommandLevel1p2True::execute() {
	static_cast<MainMenu*>(bound)->stackLevel1(true);
}