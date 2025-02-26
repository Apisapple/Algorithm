#include <iostream>

int main() {

  int n = 0, dot = 2;
  std::cin >> n;

  while (n--) {
    dot = dot * 2 - 1;
  }

  std::cout << dot * dot << '\n';
  
  return 0;
}
