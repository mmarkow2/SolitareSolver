#pragma once

#include "Card.h"

#include <vector>

class CardSet {
public:
	CardSet();

	void insertCard(Card card);
	Card peekFront();
	void popFront();
	size_t getSize();
	bool empty();
	bool printCards(unsigned int line);

	static void printSpacer();
private:
	std::vector<std::string> display;
	void regenerateDisplay();

	std::vector<Card> cards;
};