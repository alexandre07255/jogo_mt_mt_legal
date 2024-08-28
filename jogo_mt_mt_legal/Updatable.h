#pragma once
class Updatable
{
public:
	Updatable() { }
	~Updatable() { }
	virtual void execute() = 0;
};

