#include <set>
#include <string>
#include <vector>

using namespace std;

vector<bool> visited(8, false);
set<string> temp;

void dfs(vector<string> &user_id, vector<string> &banned_id, int dept) {
  if (dept == banned_id.size()) {
    string tempString;
    for (int i = 0; i < user_id.size(); i++) {
      if (visited[i]) {
        tempString += user_id[i];
      }
    }
    temp.emplace(tempString);
    return;
  }

  for (int i = 0; i < user_id.size(); i++) {
    if (visited[i] || user_id[i].size() != banned_id[dept].size())
      continue;

    bool flag = false;

    for (int j = 0; j < user_id[i].size(); j++) {
      if (banned_id[dept][j] == '*') {
        continue;
      }

      if (banned_id[dept][j] != user_id[i][j]) {
        flag = true;
        break;
      }
    }

    if (flag) {
      visited[dept] = true;
      dfs(user_id, banned_id, dept + 1);
      visited[dept] = false;
    }
  }
}

int solution(vector<string> user_id, vector<string> banned_id) { return temp.size(); }