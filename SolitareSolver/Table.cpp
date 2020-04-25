#include "Table.h"

#include <iostream>
#include <ctime>
#include <random>

Table::Table() {
	// Initialize seed
	std::srand(unsigned(std::time(0)));

	//Create deck
	std::vector<int> suits = { 0, 1, 2, 3 };

	for (int i = 0; i < 13; i++) {
		std::shuffle(suits.begin(), suits.end(), std::default_random_engine(rand()));
		for (int j = 0; j < 4; j++) {
			deck[i].push(Card(i + 1, suits[j]));
		}
	}

	piles = std::vector<CardSet>();

	CardSet pile1;
	pile1.insertCard(deck[0].top());
	deck[0].pop();

	CardSet pile2;
	pile2.insertCard(deck[1].top());
	deck[1].pop();

	CardSet pile3;
	pile3.insertCard(deck[2].top());
	deck[2].pop();

	CardSet pile4;
	pile4.insertCard(deck[3].top());
	deck[3].pop();

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