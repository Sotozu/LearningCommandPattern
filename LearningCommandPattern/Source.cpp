/*
*READ ME*

I am using the term receiver/game-actor because the command pattern more generally applies to something that is a "receiver" (which is anything that takes a command)
and the game-actor part of the term is there because of its use in interactive objects in the game we wish to command as the player.

I am using the term function/method because new programmers who come from one line of education may use either term and in my experience was the cause of simple missunderstanding when reading documentation.
Function and method are the same thing.

*/

#include <iostream>
#include <string>

#include "Command.h"
#include "FireCommand.h"
#include "JumpCommand.h"
#include "Invoker_InputHandler.h"

#include "Receiver_GameActor_KickBoxer.h"
#include "Receiver_GameActor_SumoWrestler.h"
 

int main() {

	char input;
	char fighter_option;
	int counter = 0;
	std::string fighter_name;

	/*
	The Invoker_InputHandler is something like a game controller (it takes in commands from the user and then sends them to a receiver/game-actor that we wish to command).
	The Receiver_GameActor is something like a receiver/game-actor (ex. the main character in a game that we command).
	*/

	Invoker_InputHandler* invoker = new Invoker_InputHandler;
	Receiver_GameActor_KickBoxer* game_actor_kickboxer = new Receiver_GameActor_KickBoxer;
	Receiver_GameActor_SumoWrestler* game_actor_sumowrestler = new Receiver_GameActor_SumoWrestler;


	/*
	The Invoker_InputHandler functions/methods SetButtonX and SetButtonY are executed. 
	They are passed a dynamically created FireCommand and JumpCommand respectively.
	The FireCommand and the JumpCommand are both passed the reciver/game-actor that we want to execute these commands on.
	*/
	do {


		do {
			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << "Which character type would you like to controll?" << std::endl;
			std::cout << "Sumo Wrestler: A" << std::endl;
			std::cout << "Kick Boxer: B" << std::endl;

			std::cout << std::endl;
			std::cout << "ENTER OPTION: ";
			std::cin >> fighter_option;
			
			std::cout << std::endl;
			std::cout << std::endl;
		} while (std::toupper(fighter_option) != 'A' && toupper(fighter_option) != 'B');

		if (std::toupper(fighter_option) == 'A') {
			fighter_name = "Sumo Wrestler";
			invoker->SetButtonX(new FireCommand(game_actor_sumowrestler));
			invoker->SetButtonY(new JumpCommand(game_actor_sumowrestler));

		}
		else if (std::toupper(fighter_option) == 'B') {
			fighter_name = "Kick Boxer";
			invoker->SetButtonX(new FireCommand(game_actor_kickboxer));
			invoker->SetButtonY(new JumpCommand(game_actor_kickboxer));
		}


		/*
		Now we test the Command Pattern
		*/
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Now controlling " << fighter_name << std::endl;
		std::cout << "3 Actions Total" << std::endl << std::endl;
		std::cout << "Please enter 'X', 'Y' or 'Q' to quit" << std::endl << std::endl;


		do {
			std::cout << "ENTER ACTION " << counter+1 << ": ";
			std::cin >> input;

			if (std::toupper(input) != 'Q') {
				invoker->handleInput(std::toupper(input));
			}
			counter++;
		} while (counter < 3 && std::toupper(input) != 'Q');
		std::cout << std::endl;
		counter = 0;
	} while (std::toupper(input) != 'Q');


	/*
	Delete the dynamically created objects freeing memory
	*/
	delete invoker;
	delete game_actor_kickboxer;
	delete game_actor_sumowrestler;



	return 0;
}