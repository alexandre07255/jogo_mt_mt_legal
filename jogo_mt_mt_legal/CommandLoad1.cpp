#include "CommandLoad1.h"
#include "MainMenu.h"

CommandLoad1::CommandLoad1(Scenes::Menu* _bound):Command(_bound) {
}

void CommandLoad1::execute() {
	static_cast<Scenes::MainMenu*>(bound)->load(false);
}
