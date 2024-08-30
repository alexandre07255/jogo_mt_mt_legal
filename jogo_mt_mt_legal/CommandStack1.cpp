#include "CommandStack1.h"
#include "MainMenu.h"
using namespace Scenes;

CommandStack1::CommandStack1(Menu* _bound): Command(_bound){}

CommandStack1::~CommandStack1() { }

void CommandStack1::execute() {
	static_cast<MainMenu*>(bound)->moreButtons(false);
}