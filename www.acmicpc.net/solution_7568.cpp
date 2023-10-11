#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Body {
  int weight;
  int height;
};

void init();
int main() {
  vector<Body> vec;
  int n;

  init();

  cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y = 0;

    cin >> x >> y;
    vec.push_back(Body{x, y});
  }

  for (int i = 0; i < n; i++) {
    int count = 1;

    for (int j = 0; j < n; j++) {
      if (vec[i].height < vec[j].height && vec[i].weight < vec[j].weight) {
        count++;
      }
    }

    cout << count << ' ';
  }

  return 0;
}

void init() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
}