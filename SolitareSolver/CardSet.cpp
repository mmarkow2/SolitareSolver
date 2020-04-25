#include "CardSet.h"

CardSet::CardSet() {
}

void CardSet::insertCard(Card card) {
	cards.push_back(card);
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

bool CardSet::printCards(unsigned int line, std::stringstream& output) {
	int curLine = 0;

	if (line == curLine) {
		output << " ______ ";
		return false;
	}
	curLine++;

	for (unsigned int i = 0; i + 1 < cards.size(); i++) {
		if (line == curLine) {
			output << "|  " + cards.at(i).getCardString() + " |";
			return false;
		}
		curLine++;

		if (line == curLine) {
			output << "|------|";
			return false;
		}
		curLine++;
	}

	for (int i = 0; i < 2; i++) {
		if (line == curLine) {	
			output << "|      |";
			return false;
		}
		curLine++;
	}

	if (cards.empty()) {
		if (line == curLine) {
			output << "|      |";
			return false;
		}
		curLine++;
	}
	else {
		if (line == curLine) {
			output << "|  " + cards.back().getCardString() + " |";
			return false;
		}
		curLine++;
	}

	if (line == curLine) {
		output << "|      |";
		return false;
	}
	curLine++;

	if (line == curLine) {
		output << "|______|";
		return false;
	}
	curLine++;

	//if we are past the end of the set, just print an empty line
	output << "        ";
	return true;
}

void CardSet::printSpacer(std::stringstream& output) {
	output << "          ";
}