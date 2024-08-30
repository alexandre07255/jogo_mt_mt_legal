#include "CommandRanking.h"
#include "MainMenu.h"

CommandRanking::CommandRanking(Scenes::Menu* _bound):Command(_bound) {
}

CommandRanking::~CommandRanking() { }

void CommandRanking::execute() {
	static_cast<Scenes::MainMenu*>(bound)->changeRanking();
}
