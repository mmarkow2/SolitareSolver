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

	for (int i = 0; i < 4; i++) {
		CardSet pile;
		reserves.push_back(pile);
	}

	for (int i = 0; i < 4; i++) {
		CardSet pile;
		pile.insertCard(deck[i].top());
		deck[i].pop();
		piles.push_back(pile);
	}
}

void Table::printTable() {
	for (int i = 0; i < 2; i++) {
		std::vector<CardSet> * row = i == 0 ? &reserves : &piles;
		bool finished;
		int line = 0;
		do {
			finished = true;
			for (unsigned int j = 0; j < row->size(); j++) {
				finished &= row->at(j).printCards(line);
				if (j != row->size() - 1)
					CardSet::printSpacer();
			}

			std::cout << std::endl;

			line++;
		} while (!finished);
	}
}