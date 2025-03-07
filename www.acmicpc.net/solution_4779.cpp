#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string str;

void init();
void cantor(int start, int end);
int main() {
  init();

  int N;
  while (cin >> N) {
    int strLen = pow(3, N);
    str = string(strLen, '-');

    cantor(0, strLen);
    cout << str << '\n';
  }

  return 0;
}

void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void cantor(int start, int end) {

  if (end - start == 1) {
    return;
  }

  int k = (end - start) / 3;
  for (int i = start + k; i < end - k; i++) {
    str[i] = ' ';
  }

  cantor(start, start + k);
  cantor(end - k, end);
}