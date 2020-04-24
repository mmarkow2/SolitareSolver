#pragma once

#include "Card.h"

#include <vector>

class CardSet {
public:
	CardSet();

	void insertCard(Card card);
	bool printCards(int line);

	static void printSpacer();
private:
	std::vector<std::string> display;
	void regenerateDisplay();

	std::vector<Card> cards;
};