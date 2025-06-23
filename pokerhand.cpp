#include <vector>
#include <string>

struct PokerHand {
  private:
  std::vector<Card> pokerhand;
    
  public:
  PokerHand (const char* pokerhand_unsorted){
    std::string hand = pokerhand_unsorted;
    for (size_t i {0}; i < hand.size(); i += 3){
      char card = std::string::substr(i, 2);
      pokerhand.push_back(Card(card));
    }
  }
};

struct Card {
  private:
  int value;
  enum Suit {Spades, Hearts, Diamonds, Clubs}
  Suit suit;
  
  static const std::map<char, int> cardValueMap;
  static const std::map<char, Suit> cardSuitMap;

  public:
  Card (const char c) {
    //value
    value = cardValueMap[std::string::substr(0)];
    //Suit
    suit = cardSuitMap[std::string::substr(1)];
  }
}

const std::map<char, int> Card::cardValueMap = {
  {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, 
  {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}
};

const std::map<char, Suit> cardSuitMap = {
  {'S', Suit::Spades}, {'H', Suit::Hearts}, {'D', Suit::Diamonds}, {'C', Suit::Clubs}
};


enum class Result { Win, Loss, Tie };

Result compare (const PokerHand &player, const PokerHand &opponent) {
  
  
  return Result::Loss;
}