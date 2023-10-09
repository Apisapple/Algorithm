#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 1000

vector<string> player = {"CY", "SK"};
void init();
int inputTotalStones();
int main() {

  init();

  vector<int> numberOfAct(MAX + 1, 0);
  int totalStones = inputTotalStones();

  numberOfAct[0] = 0;
  numberOfAct[1] = 1;
  numberOfAct[2] = 2;

  for (int i = 3; i <= totalStones; i++) {
    numberOfAct[i] = min(numberOfAct[i - 1] + 1, numberOfAct[i - 3] + 1);
  }

  cout << player[numberOfAct[totalStones] % 2] << '\n';

  return 0;
}

void init() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
}

int inputTotalStones() {
  int n = 0;

  cin >> n;

  return n;
}