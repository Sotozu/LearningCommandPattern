#include <iostream>
#include <string>
#include <vector>

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

	//Game actors we can controll
	Receiver_GameActor_KickBoxer* game_actor_kickboxer = new Receiver_GameActor_KickBoxer;

	Receiver_GameActor_SumoWrestler* game_actor_sumowrestler = new Receiver_GameActor_SumoWrestler;

	//Will be assigned kickboxer or sumo wrestler depending on the players choosing
	GameObject_Fighter* fighter = nullptr;

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

			//assign fighter
			fighter = game_actor_sumowrestler;
			


		}
		else if (std::toupper(fighter_option) == 'B') {
			fighter_name = "Kick Boxer";

			//assign fighter
			fighter = game_actor_kickboxer;
		}

		//the invoker is binded with the fighter so that it can access its data and execute commands on that specific fighter
		Invoker_InputHandler* invoker = new Invoker_InputHandler(fighter);

		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Now controlling " << fighter_name << std::endl;
		std::cout << "10 Actions Total" << std::endl << std::endl;
		std::cout << "'W', 'A', 'S', 'D' to move the fighter. Use 'F' to attack and 'T' to taunt" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl << std::endl;



		do {
			std::cout << "ENTER ACTION " << counter+1 << ": ";
			std::cin >> input;

			//The command returned by the invoker is binded to the fighter. So 'current_command' has actions that will explicitly call on the fighter to do something.
			current_command = invoker->handleInput(std::toupper(input));

			//Will only let movement commands be pushed into the vector
			if (toupper(input) == 'W' || toupper(input)== 'A' || toupper(input) == 'S' || toupper(input) =='D') {

				//The commands are placed into this vector and can be used later to UNDO actions
				CommandList.push_back(current_command);
			}

			if (current_command) {
				//'current_command' is binded to the fighter. We execute that command and it will cause the fighter to perform some action
				current_command->Execute();
				std::cout << std::endl;
			}
			
			//once this reaches 10 we break out of the loop
			counter++;
		} while (counter < 10);

		
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Would you like to UNDO some of your MOVEMENT commands?" << std::endl;
		std::cout << "Enter 'Y' for yes and ANY OTHER KEY for no." << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl << std::endl;

		std::cout << "OPTION: ";
		std::cin >> input;
		std::cout << std::endl;

		if (std::toupper(input) == 'Y') {

			//'command_list_index' will be updated so that we can use it to access different commands in the CommandList vector
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

				//once either end of the command list has been reached
				if (command_list_index <= 0) {
					std::cout << "NO MORE UNDO COMMANDS" << std::endl;
				}
				else if (command_list_index >= counter) {
					std::cout << "NO MORE RE-DO COMMANDS" << std::endl;
				}

			} while (std::toupper(input) == 'Z' || std::toupper(input) == 'X');

		}

		//This is done so that we can continue to test different actions from scratch when the loop starts over
		fighter->reset_position();


		//clears the saved commands so tha we can continue to test different actions from scratch when the loop starts over
		while (!CommandList.empty()) {
			delete CommandList.back();
			CommandList.pop_back();
		}

		counter = 0;

		std::cout << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "PLAY PROGRAM AGAIN?" << std::endl;
		std::cout << "PRESS 'Q' to quit or any other key to continue." << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl << std::endl;



		std::cout << "OPTION: ";
		std::cin >> input;

		std::cout << std::endl;

	} while (std::toupper(input) != 'Q');


	
	//Delete the dynamically created objects freeing memory

	delete game_actor_kickboxer;
	delete game_actor_sumowrestler;

	while (!CommandList.empty()) {
		delete CommandList.back();
		CommandList.pop_back();
	}



	return 0;
}