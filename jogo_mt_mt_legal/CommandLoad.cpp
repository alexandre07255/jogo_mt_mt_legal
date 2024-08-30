#include "CommandLoad.h"
#include "MainMenu.h"

CommandLoad::CommandLoad(Scenes::Menu* _bound) :Command(_bound) {
}

void CommandLoad::execute() {
	static_cast<Scenes::MainMenu*>(bound)->changeLoadButtons();
}
