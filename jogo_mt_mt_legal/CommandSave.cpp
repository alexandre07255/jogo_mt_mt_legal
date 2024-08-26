#include "CommandSave.h"
#include"Menu.h"

CommandSave::CommandSave(Menu* _bound):Command(_bound) {
}

void CommandSave::execute() {
	bound->save();
}