#pragma once
#include <string>

#include "Command.h"
#include "GameObject_Fighter.h"

/*
Commands like this work on a receiver/game-actor that has a function/method called fire(). It won't work on a receiver/game-actor that doesn't have the fire() function/method.

The fire command method/function is NOT defined here. It is unique to the receiver/game-actor class. 
For example if you were controlling a receiver/game-actor like an infantry soilder who has an automatic riffle equiped then the implementation of the fire command within that
infantry soilder receiver/game-actor would have their fire rate be faster than that of another receiver/game-actor like a sniper.
*/

class FireCommand : public Command {

private:

	GameObject_Fighter* fighter = nullptr;


public:
	FireCommand(GameObject_Fighter* Game_Actor_Commanded)  {
		fighter = Game_Actor_Commanded;
	}
	void Execute() const override {
		this->fighter->attack();
	}
};