#include "CommandStack1.h"
#include "CommandLevel1p2False.h"
#include "CommandLevel1p2True.h"

CommandStack1::CommandStack1(Menu* _bound): Command(_bound){}

void CommandStack1::execute() {
	Button* player2True;
	Button* player2False;
	CommandLevel1p2False* com1 = new CommandLevel1p2False(bound);
	CommandLevel1p2True* com2 = new CommandLevel1p2True(bound);

	player2True = new Button(sf::Color::Green,com2);
	player2True->setPosition(800, 500);

	bound->addButton(player2True);
	bound->addDrawable(player2True);
	bound->addUpdatable(player2True);

	player2False = new Button(sf::Color::Red,com1);
	player2False->setPosition(200, 500);

	bound->addButton(player2False);
	bound->addDrawable(player2False);
	bound->addUpdatable(player2False);
}