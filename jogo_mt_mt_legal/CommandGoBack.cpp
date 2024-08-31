#include "CommandGoBack.h"
#include "MainMenu.h"

CommandGoBack::CommandGoBack(Scenes::Menu* _bound) :Command(_bound) {
}

CommandGoBack::~CommandGoBack()
{

}

void CommandGoBack::execute() {
	static_cast<Scenes::MainMenu*>(bound)->goBack();
}

