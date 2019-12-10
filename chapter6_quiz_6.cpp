/*
6a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades).
6b) Each card will be represented by a struct named Card that contains a rank and a suit. Create the struct.
6c) Create a printCard() function that takes a const Card reference as a parameter and prints the card rank and value as a 2-letter code (e.g. the jack of spades would print as JS).
6d) A deck of cards has 52 cards. Create an array (using std::array) to represent the deck of cards, and initialize it with one of each card.
Hint: Use static_cast if you need to convert an integer into an enumerated type.
Hint: Don’t forget that std::array’s operator[] expects an index of type size_type, and that size_type must be prefixed by the full name of the array type to be accessed.
6e) Write a function named printDeck() that takes the deck as a const reference parameter and prints the values in the deck. Use a for-each loop.
6f) Write a swapCard function that takes two Cards and swaps their values.
6g) Write a function to shuffle the deck of cards called shuffleDeck(). To do this, use a for loop to step through each element of your array. Pick a random number between 1 and 52, and call swapCard with the current card and the card picked at random. Update your main function to shuffle the deck and print out the shuffled deck.

Hint: Review lesson 5.9 -- Random number generation for help with random numbers.
Reminder: Only seed your random number generator once.
6h) Write a function named getCardValue() that returns the value of a Card (e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10. Assume an Ace is worth 11).
*/

#include <iostream>
#include <array>
#include <cstdlib> //rand srand
#include <ctime>   // time

enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS
};

enum CardSuit
{
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPACE,
	MAX_SUITS
};

struct Card
{
	CardRank rank;
	CardSuit suit;
};

enum BlackjackResult
{
	BLACKJACK_PLAYER_WIN,
	BLACKJACK_DEALER_WIN,
	BLACKJACK_TIE
};

void printCard(const Card& card)
{
	switch (card.rank)
	{
	case RANK_2: std::cout << '2'; break;
	case RANK_3: std::cout << '3'; break;
	case RANK_4: std::cout << '4'; break;
	case RANK_5: std::cout << '5'; break;
	case RANK_6: std::cout << '6'; break;
	case RANK_7: std::cout << '7'; break;
	case RANK_8: std::cout << '8'; break;
	case RANK_9: std::cout << '9'; break;
	case RANK_10: std::cout << 'T'; break;
	case RANK_JACK: std::cout << 'J'; break;
	case RANK_QUEEN: std::cout << 'Q'; break;
	case RANK_KING: std::cout << 'K'; break;
	case RANK_ACE: std::cout << 'A'; break;
	}

	switch (card.suit)
	{
	case SUIT_CLUB: std::cout << 'C'; break;
	case SUIT_DIAMOND: std::cout << 'D'; break;
	case SUIT_HEART: std::cout << 'H'; break;
	case SUIT_SPACE: std::cout << 'S'; break;
	}
}

void printDeck(const std::array<Card, 52>& deck)
{
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}

	std::cout << '\n';
}

void swapCard(Card &a, Card &b)
{
	Card temp = a;
	a = b;
	b = temp;
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52>& deck)
{
	using index_t = std::array<Card, 52>::size_type;
	for (index_t index = 0; index < 52; ++index)
	{
		index_t swapIndex = getRandomNumber(0, 51);
		swapCard(deck[index], deck[swapIndex]);
	}
}

int getCardValue(const Card& card)
{
	switch (card.rank)
	{
	case RANK_2:		return 2;
	case RANK_3:		return 3;
	case RANK_4:		return 4;
	case RANK_5:		return 5;
	case RANK_6:		return 6;
	case RANK_7:		return 7;
	case RANK_8:		return 8;
	case RANK_9:		return 9;
	case RANK_10:		return 10;
	case RANK_JACK:		return 10;
	case RANK_QUEEN:	return 10;
	case RANK_KING:		return 10;
	case RANK_ACE:		return 11;
	}

	return 0;
}

char getPlayerChoice()
{
	std::cout << "(h)it or (s)tand?:";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

BlackjackResult playBlackJack(std::array<Card, 52>& deck)
{
	const Card* cardPtr = &deck[0];

	int playerTotal = 0;
	int dealerTotal = 0;

	// Deal dealer one card
	dealerTotal += getCardValue(*cardPtr++);
	std::cout << "Dealer is showing: " << dealerTotal << '\n';

	// Deal player two cards
	playerTotal += getCardValue(*cardPtr++);
	playerTotal += getCardValue(*cardPtr++);

	// Player goes first
	while (true)
	{
		std::cout << "You have: " << playerTotal << '\n';

		// See if the player has busted
		if (playerTotal > 21)
			return BLACKJACK_DEALER_WIN;

		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += getCardValue(*cardPtr++);
	}

	// If player hasn't busted, dealer goes until he has at least 17 points
	while (dealerTotal < 17)
	{
		dealerTotal += getCardValue(*cardPtr++);
		std::cout << "Dealer now has: " << dealerTotal << '\n';
	}

	// if dealer busted, player wins
	if (dealerTotal > 21)
		return BLACKJACK_PLAYER_WIN;

	// if dealer and player tie
	if (dealerTotal == playerTotal)
		return BLACKJACK_TIE;
}
		
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	std::array<Card, 52> deck;

	using index_t = std::array<Card, 52>::size_type;
	index_t card = 0;

	for(int suit = 0; suit < MAX_SUITS; ++suit)
		for (int rank = 0; rank < MAX_RANKS; ++rank)
		{
			deck[card].suit = static_cast<CardSuit>(suit);
			deck[card].rank = static_cast<CardRank>(rank);
			++card;
		}

	printDeck(deck);

	shuffleDeck(deck);

	printDeck(deck);

	char answer;
	do
	{
		if (playBlackJack(deck) == BLACKJACK_PLAYER_WIN)
			std::cout << "You win!\n";
		else if (playBlackJack(deck) == BLACKJACK_DEALER_WIN)
			std::cout << "You lose!\n";
		else if (playBlackJack(deck) == BLACKJACK_TIE)
			std::cout << "You tie!\n";

		std::cout << "Want to play (a)gain?";
		
		std::cin >> answer;
		if (answer == 'a')
		{
			shuffleDeck(deck);
		}
		else
			break;
	} while (true);
	
	return 0;
}