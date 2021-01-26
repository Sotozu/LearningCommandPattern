#pragma once
#include "Command.h"
#include "GameObject_Fighter.h"

class TauntCommand : public Command {

private:

public:

	TauntCommand() {}

	void Execute(GameObject_Fighter* Game_Actor_Commanded) const override {
		Game_Actor_Commanded->taunt();
	}
};