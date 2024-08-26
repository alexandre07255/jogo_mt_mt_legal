#include "CommandLevel2p2True.h"
#include "MainMenu.h"

CommandLevel2p2True::CommandLevel2p2True(Menu* _bound) :Command(_bound) {}

void CommandLevel2p2True::execute() {
	static_cast<MainMenu*>(bound)->stackLevel2(true);
}
