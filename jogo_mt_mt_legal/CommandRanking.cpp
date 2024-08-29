#include "CommandRanking.h"
#include "MainMenu.h"

CommandRanking::CommandRanking(Scenes::Menu* _bound):Command(_bound) {
}

void CommandRanking::execute() {
	static_cast<Scenes::MainMenu*>(bound)->changeRanking();
}
