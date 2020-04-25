#include "Table.h"

#include <exception>
#include <iostream>
#include <ctime>
#include <random>

class EmptyDeckException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "The deck is empty";
	}
};

Table::Table() {
	// Initialize seed
	std::srand(unsigned(std::time(0)));

	//Create deck
	std::vector<int> suits = { 0, 1, 2, 3 };

	for (int i = 0; i < 13; i++) {
		std::shuffle(suits.begin(), suits.end(), std::default_random_engine(rand()));
		for (int j = 0; j < 4; j++) {
			deck[i].push(Card(i + 1, suits[j]));
		}
	}

	for (int i = 0; i < 4; i++) {
		CardSet pile;
		reserves.push_back(pile);
	}

	for (int i = 0; i < 4; i++) {
		CardSet pile;
		pile.insertCard(deck[i].top());
		deck[i].pop();
		piles.push_back(pile);
	}
}

bool Table::takeTurn() {
	return true;
}

void Table::printTable() {
	for (int i = 0; i < 2; i++) {
		std::vector<CardSet> * row = i == 0 ? &reserves : &piles;
		bool finished;
		int line = 0;
		do {
			finished = true;
			for (unsigned int j = 0; j < row->size(); j++) {
				finished &= row->at(j).printCards(line);
				if (j != row->size() - 1)
					CardSet::printSpacer();
			}

			std::cout << std::endl;

			line++;
		} while (!finished);
	}
}

Card Table::drawCard() {
	//generate an array of markers for each card in the deck
	//the idea is each number in markers represents the index
	//in the deck that we would be if the cards where arranged
	//sequentially as opposed to grouped together by card value
	int markers[14];
	markers[0] = 0;

	for (int i = 1; i < 14; i++) {
		markers[i] = markers[i - 1] + deck[i - 1].size();
	}

	//if there are no cards in the deck, throw an empty deck exception;
	if (markers[13] == 0) {
		throw EmptyDeckException();
	}

	//pick a random index in our sequental card list and map it 
	//to the card value though the markers array
	int cardInd = std::rand() % markers[13];
	int deckInd = 0;
	for (; cardInd >= markers[deckInd + 1]; deckInd++);

	//take the top card off the deck and return it
	Card card = deck[deckInd].top();
	deck[deckInd].pop();
	return card;
}