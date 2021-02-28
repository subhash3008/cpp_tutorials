#include <iostream>
#include <array>
#include <algorithm>
#include <ctime>
#include <random>

enum class CardSuit {
  SUIT_CLUB,
  SUIT_HEART,
  SUIT_DIAMOND,
  SUIT_SPADE,
  MAX_SUITS
};

enum class CardRank {
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

struct Card {
  CardSuit suit{};
  CardRank rank{};
};

struct Player {
  int score {};
};

constexpr int maxScore { 21 };
constexpr int minDealerScore { 17 };

using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

void printCard(const Card& card) {
  switch(card.rank) {
    case CardRank::RANK_2: std::cout << '2'; break;
    case CardRank::RANK_3: std::cout << '3'; break;
    case CardRank::RANK_4: std::cout << '4'; break;
    case CardRank::RANK_5: std::cout << '5'; break;
    case CardRank::RANK_6: std::cout << '6'; break;
    case CardRank::RANK_7: std::cout << '7'; break;
    case CardRank::RANK_8: std::cout << '8'; break;
    case CardRank::RANK_9: std::cout << '9'; break;
    case CardRank::RANK_10: std::cout << 'X'; break;
    case CardRank::RANK_JACK: std::cout << 'J'; break;
    case CardRank::RANK_QUEEN: std::cout << 'Q'; break;
    case CardRank::RANK_KING: std::cout << 'K'; break;
    case CardRank::RANK_ACE: std::cout << 'A'; break;
    default: std::cout << '?';
  }

  switch(card.suit) {
    case CardSuit::SUIT_CLUB: std::cout << 'C'; break;
    case CardSuit::SUIT_DIAMOND: std::cout << 'D'; break;
    case CardSuit::SUIT_HEART: std::cout << 'H'; break;
    case CardSuit::SUIT_SPADE: std::cout << 'S'; break;
    default: std::cout << '?';
  }
}

int getCardValue(const Card& card) {
  switch(card.rank) {
    case CardRank::RANK_ACE: return 11;
    case CardRank::RANK_10:
    case CardRank::RANK_JACK:
    case CardRank::RANK_QUEEN:
    case CardRank::RANK_KING: return 10;
    case CardRank::RANK_2 : return 2;
    case CardRank::RANK_3 : return 3;
    case CardRank::RANK_4 : return 4;
    case CardRank::RANK_5 : return 5;
    case CardRank::RANK_6 : return 6;
    case CardRank::RANK_7 : return 7;
    case CardRank::RANK_8 : return 8;
    case CardRank::RANK_9 : return 9;
    default: return 0;
  }
}

deck_type createDeck() {
  deck_type deck {};
  index_type card {0};
  auto suits {static_cast<int>(CardSuit::MAX_SUITS)};
  auto ranks {static_cast<int>(CardRank::MAX_RANKS)};

  for (int suit {0}; suit < suits; suit++) {
    for (int rank {0}; rank < ranks; rank++) {
      deck[card].suit = static_cast<CardSuit>(suit);
      deck[card].rank = static_cast<CardRank>(rank);
      ++card;
    }
  }
  
  return deck;
}

void shuffleDeck(deck_type& deck) {
  static std::mt19937 mt { static_cast<std::mt19937::result_type>(std::time(nullptr))};
  std::shuffle(deck.begin(), deck.end(), mt);
}

void printDeck(const deck_type& deck) {
  for (const auto& card: deck) {
    printCard(card);
    std::cout << ' ';
  }
  std::cout << std::endl;
}

bool playerWantsHit() {
  while (true) {
    std::cout << "(h) to Hit or (s) or Stand : ";
    char ch {};
    std::cin >> ch;
    switch(ch) {
      case 'h':
      case 'H': return true;
      case 's':
      case 'S': return false;
    }
  }
}

// return true if player went bust. false otherwise
bool playerTurn(const deck_type& deck, index_type& nextCardIndex, Player& player) {
  while(true) {
    std::cout << "Player has : " << player.score << std::endl;
    if (player.score > maxScore) {
      return true;
    } else {
      if (playerWantsHit()) {
        player.score += getCardValue(deck[nextCardIndex]);
        std::cout << "Player got : " ;
        printCard(deck[nextCardIndex++]);
        std::cout << std::endl;
      } else {
        return false;
      }
    }
  }
}

// return true if dealer went bust.. false otherwise
bool dealerTurn(const deck_type& deck, index_type& nextCardIndex, Player& dealer) {
  while (dealer.score < minDealerScore) {
    dealer.score += getCardValue(deck[nextCardIndex++]);
  }
  return (dealer.score > maxScore);
}

bool playBlackJack(const deck_type& deck) {
  index_type nextCardIndex { 0 };
  Player dealer {getCardValue(deck[nextCardIndex++])};
  std::cout << "The dealer is showing : " << dealer.score << std::endl;
  Player player {getCardValue(deck[nextCardIndex]) + getCardValue(deck[nextCardIndex + 1])};
  nextCardIndex += 2;

  if (playerTurn(deck, nextCardIndex, player)) {
    // Player went bust
    return false;
  }

  if (dealerTurn(deck, nextCardIndex, dealer)) {
    // dealer went bust. player wins
    return true;
  }
}

int main() {
  auto deck { createDeck() };
  printDeck(deck);

  shuffleDeck(deck);
  printDeck(deck);

  if (playBlackJack(deck)) {
    std::cout << "Player WINS!!";
  } else {
    std::cout << "PLAYER LOSES!!";
  }

  return 0;
}