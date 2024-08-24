#include "CommandLevel1p2False.h"
#include "MainMenu.h"

CommandLevel1p2False::CommandLevel1p2False(Menu* _bound) :Command(_bound) {}

void CommandLevel1p2False::execute() {
	static_cast<MainMenu*>(bound)->stackLevel1(false);
}
