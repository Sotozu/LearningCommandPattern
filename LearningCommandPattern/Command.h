#pragma once
#include "GameObject_Fighter.h"

class Command {

public:
	virtual ~Command() {
	}
	virtual void Execute() = 0;
	virtual void UnExecute() = 0;

};
