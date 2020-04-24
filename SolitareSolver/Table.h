#pragma once

#include "CardSet.h"

class Table {
public:
	Table();
	void printTable();
private:
	std::vector<CardSet> piles;
};