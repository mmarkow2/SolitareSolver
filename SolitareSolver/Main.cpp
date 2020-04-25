#include "Table.h"

int main(int argc, char* argv[]) {
	Table tab;
	bool finished;
	do {
		finished = tab.takeTurn();
		tab.printTable();
	} while (!finished);

	return 0;
}