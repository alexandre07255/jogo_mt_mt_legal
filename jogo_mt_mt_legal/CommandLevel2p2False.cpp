#include "CommandLevel2p2False.h"
#include "MainMenu.h"
using namespace Scenes;

CommandLevel2p2False::CommandLevel2p2False(Menu* _bound) :Command(_bound) {}

void CommandLevel2p2False::execute() {
	static_cast<MainMenu*>(bound)->stackLevel2(false);
}

