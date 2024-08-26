#include "CommandQuit.h"
#include "SceneManager.h"

CommandQuit::CommandQuit(Menu* _bound):Command(_bound) {

}

void CommandQuit::execute() {
	SceneManager* instance = SceneManager::getInstance();

	while (instance->size() > 1) {
		instance->pop();
	}
}
