#include "Table.h"

#include <iostream>

Table::Table() {
	piles = std::vector<CardSet>();

	CardSet pile1 = CardSet();
	pile1.insertCard(Card(1, 1));
	pile1.insertCard(Card(5, 3));
	pile1.insertCard(Card(11, 2));
	pile1.insertCard(Card(12, 0));

	CardSet pile2 = CardSet();
	pile2.insertCard(Card(9, 3));

	CardSet pile3 = CardSet();

	CardSet pile4 = CardSet();
	pile4.insertCard(Card(2, 2));
	pile4.insertCard(Card(4, 0));

	piles.push_back(pile1);
	piles.push_back(pile2);
	piles.push_back(pile3);
	piles.push_back(pile4);
}

void Table::printTable() {
	int line = 0;
	bool finished;
	do {
		finished = true;
		for (int i = 0; i < piles.size(); i++) {
			finished &= piles.at(i).printCards(line);
			if (i != piles.size() - 1)
				CardSet::printSpacer();
		}

		std::cout << std::endl;

		line++;
	} while (!finished);
}