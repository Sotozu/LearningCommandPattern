#pragma once
#include <iostream>

#include "Command.h"
#include "AttackCommand.h"
#include "TauntCommand.h"
#include "MoveUpCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "MoveDownCommand.h"

#include "GameObject_Fighter.h"

/*
We can treat the Invoker_Inputhandler like a game controller.

Here we created a class that is structured to take in user input and then determine what command to execute.
Like a game controller. If your press button Y then the controller needs to send out a command for that button press.

We 


Simply. It looks at what type of input the player sent and then calls an execute command mapped to the receiver/game-actor.
*/


class Invoker_InputHandler {

private:

	GameObject_Fighter* fighter = nullptr;

	Command* ButtonX = nullptr;
	Command* ButtonY = nullptr;
	Command* ButtonZ = nullptr;


public:

	Invoker_InputHandler(GameObject_Fighter* Game_Actor_Commanded) {
		fighter = Game_Actor_Commanded;
	}

	~Invoker_InputHandler() {
		delete ButtonX;
		delete ButtonY;
		delete ButtonZ;
	}

	void SetButtonX(Command* command) {
		this->ButtonX = command;
	}
	void SetButtonY(Command* command) {
		this->ButtonY = command;
	}

	void SetButtonZ(Command* command) {
		this->ButtonZ = command;
	}

	/*
	To have undo commands work we need to have the commands hold the data that changes the object.
	We then store the inverse of that data into a part of the command called undo.
	We call undo when we want to undo that command.
	*/
	Command* handleInput(char input) {

		
		if (input == 'W') {
			int y_ = fighter->Get_Y_Pos() + 1;
			return new MoveUpCommand(fighter, y_);
		}
		else if (input == 'A') {
			int x_ = fighter->Get_X_Pos() - 1;
			return new MoveLeftCommand(fighter, x_);
		}
		else if (input == 'S') {
			int y_ = fighter->Get_Y_Pos() - 1;
			return new MoveDownCommand(fighter, y_);
		}
		else if (input == 'D') {
			int x_ = fighter->Get_X_Pos() + 1;
			return new MoveRightCommand(fighter, x_);
		}
		else if (input == 'F') {
			return new AttackCommand(fighter);
		}
		else if (input == 'T') {
			return new TauntCommand(fighter);
		}
		else {
			return NULL;
		}
	}
};