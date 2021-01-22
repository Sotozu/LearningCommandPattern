#pragma once

#pragma once
#include <iostream>
#include "GameObject_Fighter.h"

/*
The Receiver_GameActor class defined here is a represention of a generic object in a game. In reality it can be many things.
Example: main character, vehicle and other game objects

Each of the possible examples above would have their own class and respective unqiue commands. They would be activated by the Invoker through the client.

Example: main character would have it's unique functions/methods that command it to speak to NPC's, eat, jump and etc.
Example: vehicle would whave it's unique functions/methods to command it to accelerate, play the radio, turn the wheel and etc.

*/

class Receiver_GameActor_SumoWrestler : public GameObject_Fighter {

public:

	void jump() override {
		//methods to actually have the sumo wrestler attack...
		std::cout << "Sumo Wrestler: Short Jump!\n";
	}
	void attack() override {
		//methods to actually have the sumo wrestler jump...
		std::cout << "Sumo Wrestler: Smash Attack!\n";
	}

};