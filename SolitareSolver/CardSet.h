#pragma once

#include "Card.h"
#include <sstream>
#include <vector>

class CardSet {
public:
	CardSet();

	void insertCard(Card card);
	Card peekFront();
	void popFront();
	size_t getSize();
	bool empty();
	bool printCards(unsigned int line, std::stringstream& output);

	static void printSpacer(std::stringstream& output);
private:
	std::vector<Card> cards;
};