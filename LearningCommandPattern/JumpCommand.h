#pragma once

#include <string>

#include "Command.h"
#include "GameObject_Fighter.h"

/*

Commands like this work on a receiver/game-actor that has a function/method called jump(). It won't work on a receiver/game-actor that does't have the jump() function/method.

The jump command implemenatation is NOT defined here. It is unique to the receiver/game-actor.
For example if you were controlling a receiver/game-actor like a summo wreastler (who is heavy) then the implementation of the jump command within that
summo wreastler game actor would have their jump be shorter than that of a swift agile receiver/game-actor like a kick-boxer.

*/

class JumpCommand : public Command {

private:

	GameObject_Fighter* fighter = nullptr;

public:

	JumpCommand(GameObject_Fighter* Game_Actor_Commanded) {
		fighter = Game_Actor_Commanded;
	}

	void Execute() const override {
		this->fighter->jump();
	}
};