#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "inc/Deck.h"

using namespace std;

int getRandomIndex(int deckSize) {
	// generate a random index
	srand (time(NULL));
	return (rand() % deckSize);

}

std::string Deck::getCard() {
	if (availableCards > 0) {
		int index = getRandomIndex(availableCards);		
		availableCards--;
		string card = playingDeck[index];
		playingDeck.erase(playingDeck.begin() + index);
		return card;
	} else {
		return "empty";
	}
}
