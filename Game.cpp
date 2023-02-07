#include <iostream>
#include <string>
#include "inc/Game.h"
#include "inc/Player.h"
#include "inc/Deck.h"

using namespace std;

Game::Game() {
	system("clear");
	cout << "***** BACCARAT (PUNTO-BANCO) DEMO *****" << endl;
	cout << "*****       W E L C O M E !       *****" << endl;

	isGameOver = false;
	round = 1;

	cout << "Please type your name: ";
	cin >> playersName;
	cout << "Welcome " << playersName << "!" << endl;
	cout << playersName << " is now playing against the Bank\n" << endl;

	punto.setName(playersName);
	banco.setName("Banco");

	while (!isGameOver) {
		if (round < 11) {
			cout << "\nRound: " << round << endl;
			runRound();
			printOutcome();
			round++;
			cout << "Next round (Y=1/N=0)? ";
			cin >> nextRound;
			if (nextRound == 0) break;
		} else {
			isGameOver = true;
		}
	}
	
}

void Game::runRound() {

	// reset player card count and points
	punto.reset();
	banco.reset();

	// draw first 2 cards for player
	string cardA = newDeck.getCard();
	string cardB = newDeck.getCard();
	punto.addPoints(getCardPoints(cardA));
	punto.addPoints(getCardPoints(cardB));
	punto.setHand(cardA);
	punto.setHand(cardB);
	// if (punto.getPoints() > 5) {
	// 	cout << "Punto: " << cardA << ", " << cardB;
	// 	cout << "; " << punto.getPoints() << " points." << endl;
	// }

	// draw first 2 cards for bank
	string cardC = newDeck.getCard();
	string cardD = newDeck.getCard();
	banco.addPoints(getCardPoints(cardC));
	banco.addPoints(getCardPoints(cardD));
	banco.setHand(cardC);
	banco.setHand(cardD);
	// cout << "Banco: " << cardC << ", " << cardD;
	// cout << "; " << banco.getPoints() << " points." << endl;

	// If both player and bank gets an 8 or a 9
	if ( (punto.getPoints() > 7) && (banco.getPoints() > 7 ) ) {
		roundOutcome = "TIE";
	} else if ( (punto.getPoints() > 7) && (punto.getPoints() > banco.getPoints()) ) {
		roundOutcome = "PLAYER";
	} else if ( (banco.getPoints() > 7) && (banco.getPoints() > punto.getPoints()) ) {
		roundOutcome = "BANKER";
	} else {

		// RULES FOR THE PLAYER
		string puntoThirdCard;
		if (punto.getPoints() < 6) {
			string cardE = newDeck.getCard();
			puntoThirdCard = cardE;
			punto.addPoints(getCardPoints(cardE));
			punto.setHand(cardE);
			// cout << "Punto: " << cardA << ", " << cardB << ", " << cardE;
			// cout << "; " << punto.getPoints() << " points." << endl;
		}

		// RULES FOR THE BANK
		if (punto.getCardCount() < 3) {
			// player has 2 cards
			if (banco.getPoints() < 6) {
				string cardF = newDeck.getCard();
				banco.addPoints(getCardPoints(cardF));
				banco.setHand(cardF);
				// cout << "Banco: " << cardC << ", " << cardD << ", " << cardF;
				// cout << "; " << banco.getPoints() << " points." << endl;
			}

		} else {
			// player has 3 cards
			if (banco.getPoints() < 3) {
				string cardG = newDeck.getCard();
				banco.addPoints(getCardPoints(cardG));
				banco.setHand(cardG);
			} else if (banco.getPoints() == 3) {
				if (getCardPoints(puntoThirdCard) != 8) {
					string cardH = newDeck.getCard();
					banco.addPoints(getCardPoints(cardH));
					banco.setHand(cardH);
				}

			} else if (banco.getPoints() == 4) {
				if(getCardPoints(puntoThirdCard) > 1 && getCardPoints(puntoThirdCard) < 8) {
					string cardI = newDeck.getCard();
					banco.addPoints(getCardPoints(cardI));
					banco.setHand(cardI);
				}

			} else if (banco.getPoints() == 5) {
				if(getCardPoints(puntoThirdCard) > 3 && getCardPoints(puntoThirdCard) < 8) {
					string cardJ = newDeck.getCard();
					banco.addPoints(getCardPoints(cardJ));
					banco.setHand(cardJ);
				}
			} else if (banco.getPoints() == 6) {
				if(getCardPoints(puntoThirdCard) == 6 || getCardPoints(puntoThirdCard) == 7) {
					string cardK = newDeck.getCard();
					banco.addPoints(getCardPoints(cardK));
					banco.setHand(cardK);
				}
			}

		}

		// Outcome		
		if (punto.getPoints() == banco.getPoints()) {
			roundOutcome = "TIE";
		} else {
			roundOutcome = (punto.getPoints() > banco.getPoints()) ? "PLAYER" : "BANKER";
		}

	}

	// ============================
	
}

void Game::printOutcome() {

	cout << "===================================================" << endl;
	cout << "PHand\t\t" << "BHand\t\t" << "OUTCOME" << endl;
	if (punto.getCardCount() == 2) {
		if (banco.getCardCount() == 2) {
			cout << punto.hand + "\t\t" << banco.hand + "\t\t" << roundOutcome << endl;
		} else {
			cout << punto.hand + "\t\t" << banco.hand + "\t" << roundOutcome << endl;			
		}
	} else {
		if (banco.getCardCount() == 2) {
			cout << punto.hand + "\t" << banco.hand + "\t\t" << roundOutcome << endl;
		} else {
			cout << punto.hand + "\t" << banco.hand + "\t" << roundOutcome << endl;
		}
	}
	cout << "===================================================" << endl;
	
}

// get card points (integers) from cardPoints map
int Game::getCardPoints(string card) {
	return Game::cardPoints[card];
}
