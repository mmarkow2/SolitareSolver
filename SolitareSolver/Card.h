#pragma once

#include <string>

class Card {
public:
	Card(int val, int suit);

	int getVal();
	int getSuit();

	std::string getCardString();
private:
	int val;
	int suit;
};