#include <iostream>

using namespace std;

void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main() {
  init();

  int T;
  std::cin >> T;

  for (size_t i = 0; i < T; ++i) {
    int quarter = 0, dime = 0, nickel = 0, penny = 0;
    int C;

    std::cin >> C;

    quarter = C / 25;
    C %= 25;
    dime = C / 10;
    C %= 10;
    nickel = C / 5;
    C %= 5;
    penny = C;

    std::cout << quarter << " " << dime << " " << nickel << " " << penny << "\n";
  }

  return 0;
}
