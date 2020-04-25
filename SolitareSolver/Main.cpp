#include "Table.h"

int main(int argc, char* argv[]) {
	Table tab;
	bool finished;
	int turn = 1;
	do {
		finished = tab.takeTurn();
		tab.printTable(turn++);
	} while (!finished);

	return 0;
}