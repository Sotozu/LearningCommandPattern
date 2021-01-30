#pragma once
#include "Command.h"
#include "GameObject_Fighter.h"

// The invoker generates and binds this command to the fighter. It then send this command to the main part of the program where it can be executed or saved for its undo function

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