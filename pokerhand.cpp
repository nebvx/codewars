#include <vector>
#include <string>
#include <algorithm> //sort

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
  
  std::vector<Card> getVector(){
    return pokerhand;
  }
  
  
  std::vector<Card> sortHand(){
    std::vector<Card> vec = this->getVector();
    std::sort(vec.begin(), vec.end(), [](Card a, Card b) { return a.getValue() < b.getValue(); });
    return vec;
  }
  
  size_t straight() {
    size_t count {1};
    int last {0};
    int val {0};
    std::vector<Card> vec = this->sortHand();
    
    for (size_t i {0}; i < vec.size(); ++i){
      val = vec[i].getValue();
      if (last == val-1){
        ++count;
      }
      last = val;
      std::cout << "val: " << val << "\n";
    }
    
    return count;
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
  
  std::cout << "count: " << p.straight() << "\n"; 
  std::cout << "player: " << p.getFirstcard() << "\n"; 
  std::cout << "opponent: " << o.getFirstcard() << "\n"; 
  
  
  return Result::Loss;
}