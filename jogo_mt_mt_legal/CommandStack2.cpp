#include "CommandStack2.h"
#include "CommandLevel2p2False.h"
#include "CommandLevel2p2True.h"

CommandStack2::CommandStack2(Menu* _bound) : Command(_bound) {}

void CommandStack2::execute() {
	Button* player2True;
	Button* player2False;
	CommandLevel2p2False* com1 = new CommandLevel2p2False(bound);
	CommandLevel2p2True* com2 = new CommandLevel2p2True(bound);

	player2True = new Button(sf::Color::Green, com2, true);
	player2True->setPosition(800, 500);

	bound->addButton(player2True);
	bound->addDrawable(player2True);
	bound->addUpdatable(player2True);

	player2False = new Button(sf::Color::Red, com1, true);
	player2False->setPosition(200, 500);

	bound->addButton(player2False);
	bound->addDrawable(player2False);
	bound->addUpdatable(player2False);
}
