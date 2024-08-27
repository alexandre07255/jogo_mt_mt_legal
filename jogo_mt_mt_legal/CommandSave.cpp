#include "CommandSave.h"
#include"Menu.h"
using namespace Scenes;

CommandSave::CommandSave(Menu* _bound):Command(_bound) {
}

void CommandSave::execute() {
	bound->save();
}