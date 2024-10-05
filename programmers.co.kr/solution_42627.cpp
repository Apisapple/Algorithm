#include <algorithm>
#include <cassert>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Job {
  int requestTime;
  int duration;
};

struct CompareQueue {
  bool operator()(Job const &a, Job const &b) { return a.duration > b.duration; }
};

int solution(vector<vector<int>> jobs) {
  int time = 0, index = 0, numberOfJobs = jobs.size(), totalWaitTime = 0;

  sort(jobs.begin(), jobs.end());

  priority_queue<Job, vector<Job>, CompareQueue> priorityQue;
  while (index < numberOfJobs || !priorityQue.empty()) {

    while (index < numberOfJobs && jobs[index][0] <= time) {
      priorityQue.push({jobs[index][0], jobs[index][1]});
      index++;
    }

    if (!priorityQue.empty()) {
      Job currentJob = priorityQue.top();
      priorityQue.pop();
      time += currentJob.duration;
      totalWaitTime += (time - currentJob.requestTime);

    } else {
      time = jobs[index][0];
    }
  }

  return totalWaitTime / numberOfJobs;
}

int main() {
  assert(9 == solution({{0, 3}, {1, 9}, {2, 6}}));

  return 0;
}
