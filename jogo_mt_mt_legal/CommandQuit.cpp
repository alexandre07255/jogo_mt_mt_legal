#include "CommandQuit.h"
#include "SceneManager.h"
using namespace Scenes;
using namespace Managers;

CommandQuit::CommandQuit(Menu* _bound):Command(_bound) {

}

CommandQuit::~CommandQuit() { }

void CommandQuit::execute() {
	SceneManager* instance = SceneManager::getInstance();

	while (instance->size() > 1) {
		instance->pop();
	}
}
