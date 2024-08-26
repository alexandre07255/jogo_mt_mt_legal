#include "CommandStart.h"
#include "MainMenu.h"

CommandStart::CommandStart(Menu* _bound) :Command(_bound) {

}

void CommandStart::execute() {
	static_cast<MainMenu*>(bound)->changeStartButtons();
}
