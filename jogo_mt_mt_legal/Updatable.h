#pragma once
class Updatable
{
public:
	Updatable() { }
	~Updatable() { }
	virtual void movement() = 0;
};

