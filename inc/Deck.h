// Deck.h
#ifndef DECK_H
#define DECK_H

#include <vector>

class Deck {

private:
	//

public:

	int availableCards = 52;

	std::vector<std::string> playingDeck = {
		"AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC",
		"AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "TD", "JD", "QD", "KD",
		"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "JH", "QH", "KH",
		"AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS", "QS", "KS",
	};

	std::string getCard(void);

};

#endif