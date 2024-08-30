#include "CommandLevel1p2False.h"
#include "MainMenu.h"
using namespace Scenes;


CommandLevel1p2False::CommandLevel1p2False(Menu* _bound) :Command(_bound) {}

CommandLevel1p2False::~CommandLevel1p2False() { }

void CommandLevel1p2False::execute() {
	static_cast<MainMenu*>(bound)->stackLevel1(false);
}
