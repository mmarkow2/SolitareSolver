#pragma once

#include "CardSet.h"

#include <stack>

class Table {
public:
	Table();

	bool takeTurn();
	void printTable();
private:
	Card drawCard();

	std::stack<Card> deck[13];
	std::vector<CardSet> reserves;
	std::vector<CardSet> piles;
};