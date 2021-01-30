#pragma once
#include <string>

#include "Command.h"
#include "GameObject_Fighter.h"

// The invoker generates and binds this command to the fighter. It then send this command to the main part of the program where it can be executed or saved for its undo function

class MoveRightCommand : public Command {

private:
	GameObject_Fighter* fighter = nullptr;
	int x_;
	int xBefore_;
public:

	MoveRightCommand(GameObject_Fighter* Game_Actor_Commanded, int x)
		: fighter(Game_Actor_Commanded), xBefore_(0), x_(x) {}

	void Execute() override {
		xBefore_ = fighter->Get_X_Pos();
		fighter->move_right(x_);
	}

	void UnExecute() override {
		fighter->move_left(xBefore_);
	}

};
