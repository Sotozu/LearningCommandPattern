#pragma once
#include <iostream>

#include "Command.h"

/*
We can treat the Invoker_Inputhandler like a game controller.

Here we created a class that is structured to take in user input and then determine what command to execute.
Like a game controller. If your press button Y then the controller needs to send out a command for that button press.

We 


Simply. It looks at what type of input the player sent and then calls an execute command mapped to the receiver/game-actor.
*/


class Invoker_InputHandler {

private:

	Command* ButtonX;
	Command* ButtonY;
	Command* ButtonZ;

public:
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

	Command* handleInput(char input) {

		if (input == 'X') {
			return ButtonX;
		}
		else if (input == 'Y') {
			return ButtonY;
		}
		else if (input == 'Z') {
			return ButtonZ;
		}

	}

	/*void buttonXPressed() {
		if (this->ButtonX) {
			this->ButtonX->Execute();
		}
	}

	void buttonYPressed() {
		if (this->ButtonY) {
			ButtonY->Execute();
		}
	}

	void buttonZPressed() {
		if (this->ButtonZ) {
			ButtonZ->Execute();
		}
	}*/
};