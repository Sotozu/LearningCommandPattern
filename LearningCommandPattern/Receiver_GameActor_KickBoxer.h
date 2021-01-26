#pragma once
#include <iostream>
#include "GameObject_Fighter.h"

/*
The Receiver_GameActor class defined here is a represention of a generic object in a game that will receive commands. In reality it can be many things.
Example: main character, vehicle and other game objects

In this example we have a kick-boxer fighter and their unique implementation of thier jump() and attack() functions. These functions will be executed with commands.

User (presses button) -> Invoker (determines which command to send based on button pressed) -> SpecificCommand (calls the GameActors specific implementaion) -> GameActor(executes code)

*/

class Receiver_GameActor_KickBoxer : public GameObject_Fighter {

public:

	void jump() override {

		//methods to actually have the kickboxer jump...
		std::cout << "Kick Boxer: High Jump!\n";
	}
	void attack() override {
		//methods to actually have the kickboxer attack...
		std::cout << "Kick Boxer: Quick Attack!\n";
	}

	void taunt() override {
		//methods to actually have the kickboxer taunt...
		std::cout << "Kick Boxer: SCREEEEEEEEEEEEEEEEE!\n";
	}

};