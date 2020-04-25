#pragma once

#include "CardSet.h"

#include <stack>

class Table {
public:
	Table();

	void initialize();
	void clean();
	bool takeTurn();
	void printTable(std::stringstream& output);
	bool wonGame();
private:
	Card drawCard();
	bool emptyDeck();
	std::vector<int> availablePiles(Card card);

	std::stack<Card> deck[13];
	std::vector<CardSet> reserves;
	std::vector<CardSet> piles;
};