#include "CommandStack2.h"
#include "MainMenu.h"
using namespace Scenes;

CommandStack2::CommandStack2(Menu* _bound) : Command(_bound) {}

void CommandStack2::execute() {
	static_cast<MainMenu*>(bound)->moreButtons(true);
}
