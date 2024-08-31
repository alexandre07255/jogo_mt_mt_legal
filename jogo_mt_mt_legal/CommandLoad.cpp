#include "CommandLoad.h"
#include "MainMenu.h"

CommandLoad::CommandLoad(Scenes::Menu* _bound) :Command(_bound) {
}

CommandLoad::~CommandLoad() { }

void CommandLoad::execute() {
	static_cast<Scenes::MainMenu*>(bound)->changeLoadButtons();
}
