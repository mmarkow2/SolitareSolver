#pragma once

#include "CardSet.h"

#include <stack>

class Table {
public:
	Table();
	void printTable();
private:
	std::stack<Card> deck[13];
	
	std::vector<CardSet> reserves;
	std::vector<CardSet> piles;
};