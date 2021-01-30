#pragma once
#include "Command.h"
#include "GameObject_Fighter.h"

class TauntCommand : public Command {

private:
	GameObject_Fighter* fighter = nullptr;
public:

	TauntCommand(GameObject_Fighter* Game_Actor_Commanded) {
		fighter = Game_Actor_Commanded;
	}

	void Execute() override {
		fighter->taunt();
	}

	void UnExecute() override {

	}

};