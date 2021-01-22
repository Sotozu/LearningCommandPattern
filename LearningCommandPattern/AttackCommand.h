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

class AttackCommand : public Command {

private:

	GameObject_Fighter* fighter = nullptr;


public:
	AttackCommand(GameObject_Fighter* Game_Actor_Commanded)  {
		fighter = Game_Actor_Commanded;
	}
	void Execute() const override {
		this->fighter->attack();
	}
};