#include <iostream>

using namespace std;

void init();
void hanoi(int k, int from, int to, int bypass);
int main() {

  init();

  int k = 0;
  cin >> k;

  cout << (1 << k) - 1 << "\n";
  hanoi(k, 1, 3, 2);

  return 0;
}

void init() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void hanoi(int k, int from, int to, int bypass) {
  if (k == 1) {
    cout << from << " " << to << "\n";
    return;
  }

  hanoi(k - 1, from, bypass, to);
  cout << from << " " << to << "\n";
  hanoi(k - 1, bypass, to, from);
}