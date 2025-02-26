#include <iostream>
#include <string>

using namespace std;

void init();
int main() {

  string numbers;
  int numeralSystem, total = 0;

  cin >> numbers >> numeralSystem;

  for (size_t i = 0; i < numbers.size(); i++) {
    if (numbers[i] >= '0' && numbers[i] <= '9') {
      total = total * numeralSystem + (numbers[i] - '0');
    } else {
      total = total * numeralSystem + (numbers[i] - 'A' + 10);
    }
  }

  cout << total << '\n';
  return 0;
}

void init() {
  ios_base::sync_with_stdio;
  cin.tie(NULL);
  cout.tie(NULL);
}