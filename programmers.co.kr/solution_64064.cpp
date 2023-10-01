#include <set>
#include <string>
#include <vector>

using namespace std;

set<string> answerList;
vector<bool> visited(8, false);
bool isNeedToCompare(string user_id, string banned_id, int index);
void searchAnswer(vector<string> &user_id, vector<string> &bannsed_id, int index);
int solution(vector<string> user_id, vector<string> banned_id) {
  searchAnswer(user_id, banned_id, 0);
  return answerList.size();
}
void searchAnswer(vector<string> &user_id, vector<string> &banned_id, int index) {
  if (index == banned_id.size()) {
    string temp;
    for (int i = 0; i < user_id.size(); i++) {
      if (visited[i]) {
        temp += user_id[i];
      }
    }

    answerList.insert(temp);

    return;
  }

  for (int i = 0; i < user_id.size(); i++) {
    if (isNeedToCompare(user_id[i], banned_id[index], i)) {
      continue;
    }

    bool check = true;
    for (int j = 0; j < user_id[i].size(); j++) {
      if (banned_id[index][j] == '*') {
        continue;
      }

      if (banned_id[index][j] != user_id[i][j]) {
        check = false;
        break;
      }
    }

    if (check) {
      visited[i] = true;
      searchAnswer(user_id, banned_id, index + 1);
      visited[i] = false;
    }
  }
}

bool isNeedToCompare(string user_id, string banned_id, int index) {
  if (visited[index] || user_id.size() != banned_id.size()) {
    return true;
  }

  return false;
}