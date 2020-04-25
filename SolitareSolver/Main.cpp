#include "Table.h"

#include <iostream>

int main(int argc, char* argv[]) {
	Table tab;
	bool finished;
	std::stringstream output;
	for (int i = 0; i < 200; i++) {
		output.str(std::string());
		tab.clean();
		tab.initialize();
		int turn = 1;
		do {
			finished = tab.takeTurn();
			output << "-----------------------------  Turn " << turn++ << "  --------------------------------" << std::endl;
			tab.printTable(output);
		} while (!finished);
		std::cout << output.str();
		std::cout << "Finished game " << i + 1 << std::endl;
	}

	return 0;
}