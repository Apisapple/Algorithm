#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct homework {
  string subject;
  int startTime;
  int takeTime;
};

vector<homework> convertDataType(vector<vector<string>> &plans) {

  vector<homework> result;

  for (auto plan : plans) {
    homework hw;

    string hour = plan[1].substr(0, 2);
    string minute = plan[1].substr(3, 2);
    hw.subject = plan[0];
    hw.startTime = stoi(hour) * 60 + stoi(minute);
    hw.takeTime = stoi(plan[2]);

    result.push_back(hw);
  }

  return result;
}

bool compare(homework a, homework b) { return a.startTime < b.startTime; }

vector<string> solution(vector<vector<string>> plans) {
  deque<pair<string, int>> restHomework;
  vector<string> answer;
  vector<homework> plansAsHomework = convertDataType(plans);

  sort(plansAsHomework.begin(), plansAsHomework.end(), compare);

  for (int i = 0; i < plansAsHomework.size() - 1; i++) {
    int minus = plansAsHomework[i + 1].startTime - plansAsHomework[i].startTime;

    if (plansAsHomework[i].takeTime <= minus) {
      answer.push_back(plansAsHomework[i].subject);
      int tempTime = minus - plansAsHomework[i].takeTime;

      while (!restHomework.empty()) {
        int restTime = restHomework.front().second;

        if (restTime <= tempTime) {
          answer.push_back(restHomework.front().first);
          restHomework.pop_front();
          tempTime -= restTime;

        } else {
          restHomework.front().second -= tempTime;
        
          break;
        }
      }
    } else {
      restHomework.push_front(make_pair(plansAsHomework[i].subject, plansAsHomework[i].takeTime - minus));
    }
  }
  answer.push_back(plansAsHomework[plans.size() - 1].subject);

  while (!restHomework.empty()) {
    answer.push_back(restHomework.front().first);
    restHomework.pop_front();
  }

  return answer;
}
