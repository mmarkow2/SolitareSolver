#include "CardSet.h"

#include <iostream>

CardSet::CardSet() {
	regenerateDisplay();
}

void CardSet::insertCard(Card card) {
	cards.push_back(card);
	regenerateDisplay();
}

Card CardSet::peekFront() {
	return cards.back();
}

void CardSet::popFront() {
	cards.pop_back();
}

size_t CardSet::getSize() {
	return cards.size();
}

bool CardSet::empty() {
	return cards.empty();
}

bool CardSet::printCards(unsigned int line) {
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

	display.push_back(" ______ ");
	
	for (unsigned int i = 0; i + 1 < cards.size(); i++) {
		display.push_back("|  " + cards.at(i).getCardString() + " |");
		display.push_back("|------|");
	}

	for (int i = 0; i < 2; i++)
		display.push_back("|      |");

	if (cards.empty()) {
		display.push_back("|      |");
	}
	else {
		display.push_back("|  " + cards.back().getCardString() + " |");
	}

	display.push_back("|      |");
	display.push_back("|______|");
}