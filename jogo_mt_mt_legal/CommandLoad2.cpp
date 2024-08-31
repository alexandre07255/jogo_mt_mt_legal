#include "CommandLoad2.h"
#include "MainMenu.h"

CommandLoad2::CommandLoad2(Scenes::Menu* _bound) :Command(_bound) {
}

CommandLoad2::~CommandLoad2() { }

void CommandLoad2::execute() {
	static_cast<Scenes::MainMenu*>(bound)->load(true);
}
