#pragma once
#include <iostream>

#include "Command.h"

/*
The Invoker_Inputhandler is like a game controller.
Here we created a class that is structured to take in commands and then send out that specific command to the object that we are controlling.
Simply. It looks at what type of command the player sent and then relays that command to the targeted receiver/game-actor.
*/


class Invoker_InputHandler {

private:

	Command* ButtonX;
	Command* ButtonY;

public:
	~Invoker_InputHandler() {
		delete ButtonX;
		delete ButtonY;
	}

	void SetButtonX(Command* command) {
		this->ButtonX = command;
	}
	void SetButtonY(Command* command) {
		this->ButtonY = command;
	}

	void handleInput(char input) {

		if (input == 'X') {
			buttonXPressed();
		}
		else if (input == 'Y') {
			buttonYPressed();
		}

	}
	void buttonXPressed() {
		if (this->ButtonX) {
			this->ButtonX->Execute();
		}
	}

	void buttonYPressed() {
		if (this->ButtonY) {
			ButtonY->Execute();
		}
	}
};