#include "CommandSave.h"
#include"Menu.h"
#include "PauseMenu.h"
using namespace Scenes;

CommandSave::CommandSave(Menu* _bound):Command(_bound) {
}

void CommandSave::execute() {
	static_cast<PauseMenu*>(bound)->save();
}