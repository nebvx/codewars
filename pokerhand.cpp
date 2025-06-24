#include <vector>
#include <string>

struct Card {
  public:
  enum Suit {Spades, Hearts, Diamonds, Clubs};
  
  private:
  int value;
  Suit suit;
  
  static std::map<char, int> cardValueMap;
  static std::map<char, Suit> cardSuitMap;

  public:
  Card (const std::string card) {
    //value
    std::string value_str = card.substr(0);
    char c = value_str[0];
    value = cardValueMap[c];
    
    //Suit
    value_str = card.substr(1);
    c = value_str[0];
    suit = cardSuitMap[c];
  }
  
  int getValue() {
    return value;
  }

};

struct PokerHand {
  private:
  std::vector<Card> pokerhand;
    
  public:
  PokerHand (const char* pokerhand_unsorted){
    std::string hand = pokerhand_unsorted;
    for (size_t i {0}; i < hand.size(); i += 3){
      std::string card = hand.substr(i, 2);
      pokerhand.push_back(Card(card));
    }
  }
  
  int getFirstcard() {
    Card card = pokerhand[0];
    return card.getValue();
  }
};

std::map<char, int> Card::cardValueMap = {
  {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, 
  {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}
};

std::map<char, Card::Suit> Card::cardSuitMap = {
  {'S', Card::Suit::Spades}, {'H', Card::Suit::Hearts}, {'D', Card::Suit::Diamonds}, {'C', Card::Suit::Clubs}
};


enum class Result { Win, Loss, Tie };

Result compare (const PokerHand &player, const PokerHand &opponent) {
  PokerHand p = player;
  PokerHand o = opponent;
  std::cout << "player: " << p.getFirstcard(); 
  std::cout << "opponent: " << o.getFirstcard(); 
  
  
  return Result::Loss;
}