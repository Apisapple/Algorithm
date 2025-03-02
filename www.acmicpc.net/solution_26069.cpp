#include <iostream>
#include <set>

using namespace std;

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main() {

  int N;
  cin >> N;

  set<string> dancing;
  dancing.insert("ChongChong");
  for (size_t i = 0; i < N; i++) {
    string persion1, persion2;
    cin >> persion1 >> persion2;

    if (dancing.find(persion1) != dancing.end()) {
      dancing.insert(persion2);
    } else if (dancing.find(persion2) != dancing.end()) {
      dancing.insert(persion1);
    }    
  }

  cout << dancing.size() << endl;

  return 0;
}
