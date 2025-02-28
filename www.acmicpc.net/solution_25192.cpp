#include <iostream>
#include <set>
#include <string>

using namespace std;

void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main() {

  int N = 0;
  cin >> N;

  int answer = 0;
  set<string> chatRoom;
  for (int i = 1; i <= N; i++) {
    string command;
    cin >> command;

    if (command == "ENTER") {
      answer += chatRoom.size();
      chatRoom.clear();
    } else {
      chatRoom.insert(command);
    }
  }

  answer += chatRoom.size();
  cout << answer << '\n';
  return 0;
}
