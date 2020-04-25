#pragma once

#include "CardSet.h"

#include <stack>

class Table {
public:
	Table();

	bool takeTurn();
	void printTable(int turn);
private:
	Card drawCard();
	bool emptyDeck();
	std::vector<int> availablePiles(Card card);

	std::stack<Card> deck[13];
	std::vector<CardSet> reserves;
	std::vector<CardSet> piles;
};