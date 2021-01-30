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
#include <vector>
#include <list>

#include "Command.h"
#include "TauntCommand.h"
#include "Invoker_InputHandler.h"
#include "GameObject_Fighter.h"
#include "Receiver_GameActor_KickBoxer.h"
#include "Receiver_GameActor_SumoWrestler.h"
 

int main() {

	char input;
	char fighter_option;
	int counter = 0;
	std::string fighter_name;

	Command* current_command = nullptr;

	//container to hold a list of commands that we can then use to UNDO actions at a later point in time
	std::vector<Command*> CommandList;

	/*
	The Invoker_InputHandler is something like a game controller (it takes in commands from the user and then sends them to a receiver/game-actor that we wish to command).
	The Receiver_GameActor is something like a receiver/game-actor (ex. the main character in a game that we command).
	*/


	Receiver_GameActor_KickBoxer* game_actor_kickboxer = new Receiver_GameActor_KickBoxer;

	Receiver_GameActor_SumoWrestler* game_actor_sumowrestler = new Receiver_GameActor_SumoWrestler;

	GameObject_Fighter* fighter = nullptr;

	


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
			std::cout << "------------------------------------------------------------" << std::endl << std::endl;

			std::cout << "ENTER OPTION: ";
			std::cin >> fighter_option;
			
			std::cout << std::endl;
			std::cout << std::endl;
		} while (std::toupper(fighter_option) != 'A' && toupper(fighter_option) != 'B');

		if (std::toupper(fighter_option) == 'A') {
			fighter_name = "Sumo Wrestler";

			fighter = game_actor_sumowrestler;
			


		}
		else if (std::toupper(fighter_option) == 'B') {
			fighter_name = "Kick Boxer";

			fighter = game_actor_kickboxer;
		}

		Invoker_InputHandler* invoker = new Invoker_InputHandler(fighter);

		/*
		The invoker is now set with commands to the target reciever/game-actor of our choice 
		*/

		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Now controlling " << fighter_name << std::endl;
		std::cout << "10 Actions Total" << std::endl << std::endl;
		std::cout << "'W', 'A', 'S', 'D' to move the fighter. Use 'F' to attack and 'T' to taunt." << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl << std::endl;



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

				//returns the appropriate command
				current_command = invoker->handleInput(std::toupper(input));

				//will only let movement commands be pushed into the vector
				if (toupper(input) == 'W' || toupper(input)== 'A' || toupper(input) == 'S' || toupper(input) =='D') {
					CommandList.push_back(current_command);
				}

				if (current_command) {
					current_command->Execute();
					std::cout << std::endl;
				}
			}
			counter++;
		} while (counter < 10 && std::toupper(input) != 'Q');

		//resets the fighters position
		fighter->reset_position();


		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Would you like to UNDO some of your MOVEMENT commands?" << std::endl;
		std::cout << "Enter 'Y' for yes and ANY OTHER KEY for no." << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl << std::endl;

		std::cout << "OPTION: ";
		std::cin >> input;
		std::cout << std::endl;

		if (std::toupper(input) == 'Y') {
			int command_list_index = CommandList.size();

			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << CommandList.size() << " TOTAL MOVE COMMANDS" << std::endl;
			std::cout << "Press 'Z' to go back a command\nPress 'X' to go forward a command\nOR ANY OTHER KEY TO QUIT." << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl << std::endl;



			do {
				std::cout << "OPTION: ";
				std::cin >> input;

				//move down the command list
				if (std::toupper(input) == 'Z' && command_list_index > 0) {
					command_list_index--;
					CommandList[command_list_index]->UnExecute();
				}
				//move up the command list
				else if (std::toupper(input) == 'X' && command_list_index < CommandList.size()) {
					CommandList[command_list_index]->Execute();
					command_list_index++; 
				}

				if (command_list_index <= 0) {
					std::cout << "NO MORE UNDO COMMANDS" << std::endl;
				}
				else if (command_list_index >= counter) {
					std::cout << "NO MORE RE-DO COMMANDS" << std::endl;
				}

			} while (std::toupper(input) == 'Z' || std::toupper(input) == 'X');

		}

		//clears the saved commands
		while (!CommandList.empty()) {
			delete CommandList.back();
			CommandList.pop_back();
		}

		std::cout << std::endl;
		counter = 0;

	} while (std::toupper(input) != 'Q');


	/*
	Delete the dynamically created objects freeing memory
	*/
	delete game_actor_kickboxer;
	delete game_actor_sumowrestler;
	delete current_command;

	while (!CommandList.empty()) {
		delete CommandList.back();
		CommandList.pop_back();
	}



	return 0;
}