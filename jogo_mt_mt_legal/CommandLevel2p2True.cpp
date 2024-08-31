#include "CommandLevel2p2True.h"
#include "MainMenu.h"
using namespace Scenes;

CommandLevel2p2True::CommandLevel2p2True(Menu* _bound) :Command(_bound) {}

CommandLevel2p2True::~CommandLevel2p2True() { }

void CommandLevel2p2True::execute() {
	static_cast<MainMenu*>(bound)->stackLevel2(true);
}
