#include "Background.h"
#include "LevelSave.h"
using namespace Entities;

Background::Background():
	Entity(),
	scale(1)
{
}

Background::~Background()
{
	scale = -1;
}

const float Background::getScale() const
{
	return scale;
}

void Background::setScale(const float sca)
{
	scale = sca;
}

void Background::execute() { }

void Background::save(LevelSave* save) { }