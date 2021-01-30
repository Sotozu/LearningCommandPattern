
#pragma once
#include <iostream>
#include "GameObject_Fighter.h"

/*
The Receiver_GameActor class defined here is a represention of a generic object in a game. In reality it can be many things.
Example: main character, vehicle and other game objects

In this example we have a kick-boxer fighter and their unique implementation of thier move_up() and attack() functions.
*/

class Receiver_GameActor_SumoWrestler : public GameObject_Fighter {
private:

public:

	Receiver_GameActor_SumoWrestler() : GameObject_Fighter() {
		x_ = 0;
		y_ = 0;
	}

	void move_up(int y) override {
		y_ = y;
		std::cout << "Sumo Wrestler: Y-POS = " << y_ << std::endl;
	}

	void move_down(int y) override {
		y_ = y;
		std::cout << "Sumo Wrestler: Y-POS = " << y_ << std::endl;
	}

	void move_left(int x) override {
		x_ = x;
		std::cout << "Sumo Wrestler: X-POS = " << x_ << std::endl;
	}

	void move_right(int x) override {
		x_ = x;
		std::cout << "Sumo Wrestler: X-POS = " << x_ << std::endl;
	}

	void attack() override {
		std::cout << "Sumo Wrestler: Smash Attack!\n";
	}

	void taunt() override {
		std::cout << "Sumo Wrestler: You can't milk those!\n";
	}

	void reset_position() override {
		x_ = 0;
		y_ = 0;
	}

	~Receiver_GameActor_SumoWrestler(){}
};