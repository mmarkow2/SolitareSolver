#include "CardSet.h"

#include <iostream>

CardSet::CardSet() {
	cards = std::vector<Card>();
	display = std::vector<std::string>();
}

void CardSet::insertCard(Card card) {
	cards.push_back(card);
	regenerateDisplay();
}

bool CardSet::printCards(int line) {
	if (line >= display.size()) {
		std::cout << "        ";
		return true;
	}
	std::cout << display.at(line);
	return false;
}

void CardSet::printSpacer() {
	std::cout << "          ";
}

void CardSet::regenerateDisplay() {
	display.clear();

	if (cards.empty())
		return;

	display.push_back(" ______ ");
	
	for (int i = 0; i < cards.size() - 1; i++) {
		display.push_back("|  " + cards.at(i).getCardString() + "  |");
		display.push_back("|------|");
	}

	for (int i = 0; i < 2; i++)
		display.push_back("|      |");

	display.push_back("|  " + cards.back().getCardString() + "  |");

	display.push_back("|      |");
	display.push_back("|______|");
}