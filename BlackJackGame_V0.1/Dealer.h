#pragma once

#include "Person.h"
#include "Dealer.h"
#include "Deck.h"
#include "Card.h"



using namespace std;

class Dealer :
	public Person
{
private:
	vector<Card> _dealerHand;
	vector<int> _dealerHandValues;
	bool _dealerBusted = false;
	int _dealerTotal = 0;

public:
	int calculateTotalAndPrintHand(vector<Card> &handToPrint, vector<int> &handValues, bool printHand);
	void dealCards(vector<Card> &deckCards, vector<Card> &playerHand);
	void printDealerHand();
	void printDealerHandWithHiddenCard();
	vector<Card>& getDealerHand(){ return _dealerHand; }
	void playAndDrawFromDeck();
	int getDealerTotal(){ return _dealerTotal; }
	bool getDealerBusted(){ return _dealerBusted; }
	~Dealer();
};



