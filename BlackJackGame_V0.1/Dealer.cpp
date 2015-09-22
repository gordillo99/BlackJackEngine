#include "stdafx.h"
#include "Deck.h"
#include "Card.h"
#include "Dealer.h"
#include "GameEngine.h"

using namespace std;

void Dealer::dealCards(vector<Card> &deckCards, vector<Card> &playerHand)
{

	Card firstPlayerCard = deckCards.at(0);
	Card firstDealerCard = deckCards.at(1);
	Card secondPlayerCard = deckCards.at(2);
	Card secondDealerCard = deckCards.at(3);

	deckCards.erase(deckCards.begin(), deckCards.begin() + 3);

	_dealerHand.push_back(firstDealerCard);
	_dealerHand.push_back(secondDealerCard);

	playerHand.push_back(firstPlayerCard);
	playerHand.push_back(secondPlayerCard);
}

void Dealer::printDealerHand()
{
	cout << "\nDealer's Hand\n\n";

	for (vector<Card>::iterator it = getDealerHand().begin(); it != getDealerHand().end(); ++it)
	{
		Card c = *it;
		c.printCardValueAndSuit();
	}

	cout << "\n";
}

void Dealer::printDealerHandWithHiddenCard()
{
	cout << "\nDealer's Hand\n\n";
	Card firstCard = getDealerHand().at(0);
	firstCard.printCardValueAndSuit();
	cout << "Card: ???????????\n"; //printing the mysterious card
}

void Dealer::playAndDrawFromDeck()
{
	int dealersTotal = 0;
	bool keepLoopGoing = false;

	do
	{
		//dealersTotal = calculateTotalAndPrintHand(getDealerHand(), getDealerHandValues(), false, "Dealer"); 
		dealersTotal = 0;

		if (dealersTotal > 21)
		{
			//indicate that dealer has busted
			break;
		}
		else if (dealersTotal > 16 && dealersTotal < 22)
		{
			//indicate the dealers total 
			break;
		}
		else if (dealersTotal < 17)
		{
			//dealer hits
			keepLoopGoing = true;
		}
	} while (keepLoopGoing);
}

Dealer::~Dealer()
{
}
