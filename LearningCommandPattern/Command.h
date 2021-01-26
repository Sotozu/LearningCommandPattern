#pragma once
#include "GameObject_Fighter.h"

class Command {

public:
	virtual ~Command() {
	}
	virtual void Execute(GameObject_Fighter* Game_Actor_Commanded) const = 0;

};
