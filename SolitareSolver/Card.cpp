#include "Card.h"

Card::Card(int val, int suit) {
	this->val = val;
	this->suit = suit;
}

int Card::getVal() {
	return val;
}

int Card::getSuit() {
	return suit;
}

std::string Card::getCardString() {
	std::string cardString = "";
	if (val == 1)
		cardString = "A ";
	else if (val > 1 && val < 10)
		cardString = std::to_string(val) + " ";
	else if (val == 10)
		cardString = std::to_string(val);
	else if (val == 11)
		cardString = "J ";
	else if (val == 12)
		cardString = "Q ";
	else if (val == 13)
		cardString = "K ";

	char suits[] = { 'H', 'D', 'S', 'C' };
	cardString += suits[suit];

	return cardString;
}