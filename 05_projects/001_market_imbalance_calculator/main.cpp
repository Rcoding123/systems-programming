#include <cmath>
#include <iostream>

/* The program asks for bid quantity and ask quantity,
 * then tells you whether the market is buyer-heavy, seller-heavy, or balanced.
 */

int getBidQuantity() {
  std::cout << "Enter a bid quantity: ";
  int bid{};
  std::cin >> bid;

  return bid;
}

int getAskQuantity() {
  std::cout << "Enter an ask quantity: ";
  int ask{};
  std::cin >> ask;

  return ask;
}

float calculateBidImbalance(int bids, int asks) {
  return std::round(((float(bids) / (bids + asks)) * 100));
}

float calculateAskImbalance(int bids, int asks) {
  return std::round(((float(asks) / (bids + asks)) * 100));
}

void printResult(float bid_imbalance, float ask_imbalance) {
  if (bid_imbalance > ask_imbalance) {
    std::cout << "Bid imbalance: " << bid_imbalance << "%" << '\n';
  } else {
    std::cout << "Ask imbalance: " << ask_imbalance << "%" << '\n';
  }
}

void classifyMarketPressure(float bid_imbalance, float ask_imbalance) {
  if (bid_imbalance > ask_imbalance) {
    std::cout << "Result: " << "Buyer-heavy" << '\n';
  } else {
    std::cout << "Result: " << "Seller-heavy" << '\n';
  }
}

int main() {
  int bid_quantity = getBidQuantity();
  int ask_quantity = getAskQuantity();
  std::cout << "Total quantity: " << bid_quantity + ask_quantity << '\n';

  float bid_imbalance{calculateBidImbalance(bid_quantity, ask_quantity)};
  float ask_imbalance{calculateAskImbalance(bid_quantity, ask_quantity)};
  printResult(bid_imbalance, ask_imbalance);
  classifyMarketPressure(bid_imbalance, ask_imbalance);

  return 0;
}
