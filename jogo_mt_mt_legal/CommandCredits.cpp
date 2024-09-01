#include "CommandCredits.h"
#include "MainMenu.h"
using namespace Scenes;
CommandCredits::CommandCredits(Menu* _bound):Command(_bound) {

}

void CommandCredits::execute() {
	static_cast<MainMenu*>(bound)->changeCreditsButtons();
}

