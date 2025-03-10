#include <iostream>

using namespace std;

void print_star(int x, int y, int n);

int main() {
  /* code */

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      print_star(i, j, n);
    }
    cout << '\n';
  }

  return 0;
}

void print_star(int x, int y, int n) {
  if ((x / n) % 3 == 1 && (y / n) % 3 == 1) {
    cout << ' ';
  } else {
    if (n / 3 == 0) {
      cout << '*';
    } else {
      print_star(x, y, n / 3);
    }
  }
}
