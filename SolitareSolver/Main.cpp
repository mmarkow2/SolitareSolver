#include "Table.h"

#include <iostream>

const int NUM_GAMES = 1;

int main(int argc, char* argv[]) {
	Table tab;
	bool finished = false;
	std::stringstream output;
	int wins = 0;
	int gameNum = 0;
	while (gameNum < NUM_GAMES) {
		output.str(std::string());
		tab.clean();
		tab.initialize();
		int turn = 0;
		do {
			finished = tab.takeTurn();
			output << "-----------------------------  Turn " << ++turn << "  --------------------------------" << std::endl;
			tab.printTable(output);
		} while (!finished);
		std::cout << output.str();
		std::cout << "Finished game " << ++gameNum << std::endl;

		if (tab.wonGame()) {
			std::cout << output.str();
			wins++;
		}
	}

	std::cout << "-----------------------------  Summary   -----------------------------------" << std::endl;
	std::cout << "Wins: "<< wins << std::endl;
	std::cout << "Loses: " << gameNum - wins << std::endl;
	std::cout << "Total Games: " << gameNum << std::endl;
	std::cout << "Win rate: " << (float) wins / gameNum * 100 << "%" << std::endl;
	std::cout << "-----------------------------  Summary   -----------------------------------" << std::endl;

	return 0;
}