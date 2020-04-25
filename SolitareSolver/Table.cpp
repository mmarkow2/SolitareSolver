#include "Table.h"

#include <exception>
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
}

void Table::initialize() {
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

void Table::clean() {
	for (int i = 0; i < 13; i++) {
		deck[i] = std::stack<Card>();
	}
	reserves.clear();
	piles.clear();
}

/*
In here lies the core logic to the solver.
We have the following resources available to us:

Deck: This contains the remaining cards available in the deck 
      (of course the order is an unknown to us)

Reserves: Our inventory piles of which only the top card may be used

Piles: Our "win condition." We seek to make all piles have 13 cards ending with a king.
       Every pile has a multiple (the first pile moves in multiples of 1, 
	   the second pile multiples of 2 and so on up to 4 piles).
	   Cards can overlap after king and proceed to ace (until a pile has 13 cards)

*/
bool Table::takeTurn() {
	//First check if we can play any of our reserve cards and play them if so
	for (unsigned int i = 0; i < reserves.size(); i++) {
		CardSet * currentReserve = &reserves.at(i);

		//if we have a card in this reserve
		if (!currentReserve->empty()) {
			//check if the top card can be placed anywhere
			Card card = currentReserve->peekFront();
			std::vector<int> potentials = availablePiles(card);

			if (!potentials.empty()) {
				//move the card between piles
				currentReserve->popFront();
				piles.at(potentials.front()).insertCard(card);
			}
		}
	}

	//draw a card from the deck if we can't play any reserve cards
	Card currentCard = drawCard();
	std::vector<int> potentials = availablePiles(currentCard);

	if (!potentials.empty()) {
		piles.at(potentials.front()).insertCard(currentCard);
	}
	else {
		//ideally, we have a strategy for where to place the reserve cards 
		//but for now just place them randomly
		reserves.at(std::rand() % reserves.size()).insertCard(currentCard);
	}

	//the game ends if the deck is empty
	//we won if the reserves are empty at this point and lost if not
	return emptyDeck();
}

void Table::printTable(std::stringstream& output) {
	for (int i = 0; i < 2; i++) {
		std::vector<CardSet> * row = i == 0 ? &reserves : &piles;
		bool finished;
		int line = 0;
		do {
			finished = true;
			for (unsigned int j = 0; j < row->size(); j++) {
				finished &= row->at(j).printCards(line, output);
				if (j != row->size() - 1)
					CardSet::printSpacer(output);
			}

			output << std::endl;

			line++;
		} while (!finished);
	}
}

bool Table::wonGame() {
	bool won = true;

	for (int i = 0; i < reserves.size(); i++) {
		won &= reserves.at(i).empty();
	}
	return won;
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

bool Table::emptyDeck() {
	//the deck is not empty if a single val has a card
	bool empty = true;
	for (unsigned int i = 0; i < 13; i++) {
		empty &= deck[i].empty();
	}

	return empty;
}

std::vector<int> Table::availablePiles(Card card) {
	std::vector<int> result;
	for (unsigned int i = 0; i < piles.size(); i++) {
		int cardVal = piles.at(i).peekFront().getVal();
		int nextCardVal = (cardVal + (i + 1)) % 13;

		if (card.getVal() == nextCardVal) {
			result.push_back(i);
		}
	}
	return result;
}