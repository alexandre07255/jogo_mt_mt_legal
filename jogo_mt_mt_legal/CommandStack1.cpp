#include "CommandStack1.h"
#include "MainMenu.h"

CommandStack1::CommandStack1(Menu* _bound): Command(_bound){}

void CommandStack1::execute() {
	static_cast<MainMenu*>(bound)->moreButtons(false);
}