// Game.h
#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"
#include <map>

class Game {

private:
	// card-points mapping
	std::map<std::string, int> cardPoints {
		{"AC", 1}, {"2C", 2}, {"3C", 3}, {"4C", 4}, {"5C", 5}, {"6C", 6}, {"7C", 7}, {"8C", 8}, {"9C", 9}, {"TC", 0}, {"JC", 0}, {"QC", 0}, {"KC", 0},
		{"AD", 1}, {"2D", 2}, {"3D", 3}, {"4D", 4}, {"5D", 5}, {"6D", 6}, {"7D", 7}, {"8D", 8}, {"9D", 9}, {"TD", 0}, {"JD", 0}, {"QD", 0}, {"KD", 0},
		{"AH", 1}, {"2H", 2}, {"3H", 3}, {"4H", 4}, {"5H", 5}, {"6H", 6}, {"7H", 7}, {"8H", 8}, {"9H", 9}, {"TH", 0}, {"JH", 0}, {"QH", 0}, {"KH", 0},
		{"AS", 1}, {"2S", 2}, {"3S", 3}, {"4S", 4}, {"5S", 5}, {"6S", 6}, {"7S", 7}, {"8S", 8}, {"9S", 9}, {"TS", 0}, {"JS", 0}, {"QS", 0}, {"KS", 0}
	};	

public:

	std::string playersName;

	short int round;

	bool isGameOver;

	bool nextRound;

	// Round outcome
	std::string roundOutcome;

	// Card deck
	Deck newDeck;

	// Players
	Player punto;
	Player banco;

	// Player's points
	unsigned int puntoPoints;
	unsigned int bancaPoints;

	Game(void);

	void runRound();

	void printOutcome();

	int getCardPoints(std::string card);

};


#endif
