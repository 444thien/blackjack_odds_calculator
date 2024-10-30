#include "blackjack.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	const map<char, int> CARDVALUES = {
		{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6',6},
		{'7', 7}, {'8', 8}, {'9', 9}, {'10', 10}, {'J', 10},
		{'Q', 10}, {'K', 10}, {'A', 11}
	};
	char continuePlaying = 'y';
	char userCard;

	while (continuePlaying == 'y' || continuePlaying == 'Y')
	{
		map<char, int> deck;
		vector<char> userHand;
		populateDeck(deck);

		cout << "Enter your hand (e.g., 3 Q A): ";
		while (cin >> userCard)
		{
			userCard = toupper(userCard);
			if (isValidCard(userCard, CARDVALUES))
			{
				userHand.push_back(userCard);
			}
			else
			{
				cout << "Invalid input, please try again (e.g., 3 Q A): ";
				cin.clear();
				continue;
			}
			if (cin.peek() == '\n') break;
		}

		updateDeck(userHand, deck);
		int userHandValue = calculateHandValue(userHand, CARDVALUES);

		cout << "You hand value: " << userHandValue << endl;
		cout << "Odds of busting on your next turn: " << calculateBustChance(userHandValue, deck, CARDVALUES) << "%\n";

		cout << "Do you want to enter another hand (y/n)?\n";
		cin >> continuePlaying;
		cin.clear();
	}
	cout << "Thank you for your time!\n";
	return 0;
}