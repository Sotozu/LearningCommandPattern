#pragma once

#include <string>

#include "Command.h"
#include "GameObject_Fighter.h"

// The invoker generates and binds this command to the fighter. It then send this command to the main part of the program where it can be executed or saved for its undo function

class MoveDownCommand : public Command {
private:
	GameObject_Fighter* fighter = nullptr;
	int y_;
	int yBefore_;
public:

	MoveDownCommand(GameObject_Fighter* Game_Actor_Commanded, int y)
		: fighter(Game_Actor_Commanded), yBefore_(0), y_(y) {}

	void Execute() override {
		yBefore_ = fighter->Get_Y_Pos();
		fighter->move_down(y_);
	}

	void UnExecute() override {
		fighter->move_down(yBefore_);
	}
};