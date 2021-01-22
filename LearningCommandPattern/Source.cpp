/*
*READ ME*

I am using the term receiver/game-actor because the command pattern more generally applies to something that is a "receiver" (which is anything that takes a command)
and the game-actor part of the term is there because of its use in interactive objects in the game we wish to command as the player.


0. Invoker is mapped with specific commands to a specfic receiver/game-actor
1. User presses button 
2. Invoker determines which specific command to execute based on the button pressed
3. Specific command calls the receiver/game-actor specific implementaion
4. game-actor executes code changing an element of game-actor
5. Game loop updates with changes to game-actor

*/

#include <iostream>
#include <string>

#include "Command.h"
#include "AttackCommand.h"
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
	The Invoker_InputHandler functions SetButtonX and SetButtonY are passed a dynamically created AttackCommand and JumpCommand respectively.
	These paased in commands to the invoker are initialized with the targeted receiver/game-actor that we wish to execute the commands on.
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
			invoker->SetButtonX(new AttackCommand(game_actor_sumowrestler));
			invoker->SetButtonY(new JumpCommand(game_actor_sumowrestler));

		}
		else if (std::toupper(fighter_option) == 'B') {
			fighter_name = "Kick Boxer";
			invoker->SetButtonX(new AttackCommand(game_actor_kickboxer));
			invoker->SetButtonY(new JumpCommand(game_actor_kickboxer));
		}


		/*
		The invoker is now set with commands to the target reciever/game-actor of our choice 
		*/

		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Now controlling " << fighter_name << std::endl;
		std::cout << "3 Actions Total" << std::endl << std::endl;
		std::cout << "Please enter 'X', 'Y' or 'Q' to quit" << std::endl << std::endl;


		do {
			std::cout << "ENTER ACTION " << counter+1 << ": ";
			std::cin >> input;

			
			if (std::toupper(input) != 'Q') {
				/*
				The invoker receives user input (a button press).
				At his point the invoker knows the receiver/game-actor that it will execute a command on.
				The invoker knows which type of command to send BUT it doesn't know the hard coded implemenation of the command BECAUSE...
				that is defined inside the receiver/game-acotr which the invoker is sending commands to.
				*/
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