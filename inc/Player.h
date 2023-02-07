// Player.h
#ifndef PLAYER_H
#define PLAYER_H

class Player {

private:
	//

public:

	std::string name;

	int points;

	int numberOfCards;

	std::string hand;

	Player(void);
	
	std::string getName(void);

	void setName(std::string newName);

	// std::string getOutcome(void);

	int getPoints(void);

	void addPoints(int cardPoints);

	int getCardCount(void);

	void reset(void);

	void setHand(std::string newCard);

};

#endif
