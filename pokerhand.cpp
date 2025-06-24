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
  
  Suit getSuit(){
    return suit;
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
    std::sort(pokerhand.begin(), pokerhand.end(), [](Card a, Card b) { return a.getValue() < b.getValue(); });
  }
  
  int getFirstcard() {
    Card card = pokerhand[0];
    return card.getValue();
  }
  
  std::vector<Card> getVector(){
    return pokerhand;
  }
  
  
  int straight() {
    size_t count {1};
    int last {0};
    int val {0};
    std::vector<Card> vec = pokerhand;
    
    for (size_t i {0}; i < vec.size(); ++i){
      val = vec[i].getValue();
      if (last == val-1){
        ++count;
      }
      last = val;
      //std::cout << "val: " << val << "\n";
    }
    
    return count == 5 ? val : 0;
  }
  
  bool fullHouse() {
    std::vector<Card> vec = pokerhand;
    return true;
  }
  
  bool flush() {
    std::vector<Card> vec = pokerhand;
    Card::Suit suit;
    
    for (size_t i {0}; i < 4; ){
      suit = vec[i++].getSuit();
      if (suit != vec[i].getSuit()) {
        return false;
      }
      //std::cout << "z: " << suit << "\n";
    }
    
    return true;
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
  int a = p.straight();
  bool s = o.flush();
  int straight = a;
  std::cout << "straight: " << p.straight() << "\n"; 
  
  //straight
  return p.straight() > o.straight() ? Result::Win : Result::Loss;
}