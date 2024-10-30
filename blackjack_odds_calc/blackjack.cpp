#include "blackjack.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isValidCard(char card, const map<char, int>& cardValues)
{
	return cardValues.find(card) != cardValues.end();
}

int calculateHandValue(vector<char>& hand, const map<char, int>& cardValues)
{
	int value = 0;
	int aceCount = 0;

	for (char c : hand)
	{
		value += cardValues.at(c);
		if (c == 'A') aceCount++;
	}

	while (value > 21 && aceCount > 0)
	{
		value -= 10;
		aceCount--;
	}

	return value;
}

void populateDeck(map<char, int>& deck)
{
	deck = {
		{'2', 4}, {'3', 4}, {'4', 4}, {'5', 4}, {'6',4},
		{'7', 4}, {'8', 4}, {'9', 4}, {'10', 4}, {'J', 4},
		{'Q', 4}, {'K', 4}, {'A', 4},
	};
}

void updateDeck(vector<char>& userHand, map<char, int>& deck)
{
	for (char c : userHand)
	{
		if (deck[c] > 0) deck[c]--;
	}
}

double calculateBustChance(int handValue, const map<char, int>& deck, const map<char, int>& cardValues)
{
	int bustCards = 0;
	int totalCards = 0;

	for (auto i = deck.begin(); i != deck.end(); i++)
	{
		char currCard = i->first;
		int numOfC = i->second;
		int currCardValue = cardValues.at(currCard);

		if (currCard == 'A')
		{
			if ((handValue + 1 > 21) && (handValue + 11 > 21))
			{
				bustCards += numOfC;
			}
		}
		else
		{
			if (handValue + currCardValue > 21) bustCards += numOfC;
		}
		totalCards += numOfC;
	}

	return static_cast<double>(bustCards) / totalCards * 100;
}