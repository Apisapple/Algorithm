#include <algorithm>
#include <iostream>

using namespace std;
string temp_sentence = "";
void init() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
}

void isPossible(string source, string target) {
  if (source == target) {
    cout << 1 << '\n';
    exit(0);
  }

  if (source.size() >= target.size()) {
    return;
  }

  if (target[target.size() - 1] == 'A') {
    temp_sentence = target;
    temp_sentence.erase(temp_sentence.size() - 1);
    isPossible(source, temp_sentence);
  }

  if(target[0] == 'B') {
    temp_sentence = target;
    temp_sentence.erase(temp_sentence.begin());
    reverse(temp_sentence.begin(), temp_sentence.end());
    isPossible(source, temp_sentence);
  }
}

int main() {
  init();

  string source, target;

  cin >> source;
  cin >> target;

  isPossible(source, target);

  cout << 0 << '\n';
  return 0;
}