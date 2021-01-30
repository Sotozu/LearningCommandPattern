#pragma once
#include <string>

#include "Command.h"
#include "GameObject_Fighter.h"

/*
This command works only on AND will/should only be sent to a receiver/game-actor that has a function called attack() implemented in itself. It won't work on a receiver/game-actor that doesn't have the attack() function.

Again, The attack() function is NOT defined here. It is uniquely implemented in the receiver/game-actor class.

WITHIN THIS CLASS WE ARE ARE CALLING ON THE RECEIVER/GAME-ACTOR TO EXECUTE IT'S ATTACK FUNCTION
*/


/*
If a receiver/game-actor like an kick-boxer fighter were passed into this command then it would call on it's unique implementation of the attack() function. The unique implementation of the attack() function within that
kick-boxer fighters would be different than that of another fighters implementation of the attack() function, like a sumo wrestler.
*/

class MoveLeftCommand : public Command {

private:
	GameObject_Fighter* fighter = nullptr;

	int x_;

	int xBefore_;

public:

	MoveLeftCommand(GameObject_Fighter* Game_Actor_Commanded, int x) 
		: fighter(Game_Actor_Commanded), xBefore_(0), x_(x) {}


	void Execute() override {

		xBefore_ = fighter->Get_X_Pos();
		fighter->move_left(x_);
	}

	void UnExecute() override {
		fighter->move_left(xBefore_);
	}

};
