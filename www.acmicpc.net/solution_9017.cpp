#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void init();
vector<int> input_data(int dataCount);
int get_answer(vector<int> datas);
bool compair(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  if (a.second.first < b.second.first) {
    return true;
  } else if (a.second.first == b.second.first && a.second.second < b.second.second) {
    return true;
  }

  return false;
}

bool is_contains(vector<int> datas, int data);
int main() {
  init();

  int testCount = 0;
  cin >> testCount;

  for (int i = 0; i < testCount; i++) {
    int dataCount = 0;
    cin >> dataCount;

    vector<int> datas = input_data(dataCount);
    int answer = get_answer(datas);

    cout << answer << '\n';
  }

  return 0;
}

void init() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
}

vector<int> input_data(int dataCount) {
  vector<int> datas(dataCount, 0);

  for (int i = 0; i < dataCount; i++) {
    cin >> datas[i];
  }

  return datas;
}

int get_answer(vector<int> datas) {
  map<int, int> teamMemberCount;
  map<int, vector<int>> finishedTeams;
  vector<pair<int, pair<int, int>>> finishedTeamsPoints;
  vector<int> exceptionTeams;

  for (int i = 0; i < datas.size(); i++) {
    teamMemberCount[datas[i]]++;
  }

  for (auto iter = teamMemberCount.begin(); iter != teamMemberCount.end(); iter++) {
    if (iter->second < 6) {
      exceptionTeams.push_back(iter->first);
    }
  }

  int point = 1;
  for (int i = 0; i < datas.size(); i++) {
    if (!is_contains(exceptionTeams, datas[i])) {
      if (finishedTeams[datas[i]].size() <= 5) {
        finishedTeams[datas[i]].push_back(point);
      }

      point++;
    }
  }

  for (auto iter = finishedTeams.begin(); iter != finishedTeams.end(); iter++) {
    int teamNumber = iter->first;
    vector<int> points = iter->second;

    int total = 0;
    for (int i = 0; i < points.size() - 2; i++) {
      total += points[i];
    }

    finishedTeamsPoints.push_back(make_pair(teamNumber, make_pair(total, points[4])));
  }

  sort(finishedTeamsPoints.begin(), finishedTeamsPoints.end(), compair);

  return finishedTeamsPoints.at(0).first;
}

bool is_contains(vector<int> datas, int data) { return (find(datas.begin(), datas.end(), data) != datas.end()); }