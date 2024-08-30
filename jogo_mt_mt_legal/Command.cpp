#include "Command.h"
using namespace Scenes;

Command::Command(Menu* _bound) {
	bound = _bound;
}

Command::~Command()
{
	bound = NULL;
}