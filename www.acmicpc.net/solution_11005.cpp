#include <iostream>
#include <string>

void init() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
}

int main() {
  init();

  std::string result = "";
  int number, numericSystem;
  std::cin >> number >> numericSystem;

  while (number > 0) {
    int remainder = number % numericSystem;
    if (remainder < 10) {
      result.push_back(remainder + '0');
    } else {
      result.push_back(remainder - 10 + 'A');
    }
    number /= numericSystem;
  }

  std::cout << std::string(result.rbegin(), result.rend()) << '\n';
  return 0;
}
