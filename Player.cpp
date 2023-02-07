#include <iostream>
#include <string>
#include "inc/Player.h"

Player::Player(void) {
	numberOfCards = 0;
	points = 0;

}

std::string Player::getName() {
	return name;

}

void Player::setName(std::string newName) {
	name = newName;
}

// Return accumulated points
int Player::getPoints(void) {
	return points;
}

// Set card points, increase numberOfCards
void Player::addPoints(int cardPoints) {
	points += cardPoints;
	numberOfCards++;
	if (points > 9) {
		points %= 10;
	}

}

int Player::getCardCount(void) {
	return numberOfCards;
}

void Player::reset(void) {
	numberOfCards = 0;
	points = 0;
	hand = "";
}

void Player::setHand(std::string newCard) {
	if (hand == "") {
		hand = newCard;
	} else {
		hand = hand + "," + newCard;
	}
}
