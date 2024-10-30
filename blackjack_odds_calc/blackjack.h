// blackjack.h
#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>
#include <map>

bool isValidCard(char card, const std::map<char, int>& cardValues);
int calculateHandValue(std::vector<char>& hand, const std::map<char, int>& cardValues);
void populateDeck(std::map<char, int>& deck);
void updateDeck(std::vector<char>& userHand, std::map<char, int>& deck);
double calculateBustChance(int handValue, const std::map<char, int>& deck, const std::map<char, int>& cardValues);

#endif