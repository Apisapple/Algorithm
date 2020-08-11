#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(pair<int, int> task1, pair<int, int> task2) {
    if(task1.second == task2.second) {
        return task1.first < task2.first;
    } else {
        return task1.second < task2.second;
    }
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start_time = 0;
    int duration = 0;
    vector<pair<int, int>> jobs_pair;

    for(int i = 0; i < jobs.size(); i ++) {
        jobs_pair.push_back(make_pair(jobs[i][0],jobs[i][1]));
    }
    sort(jobs_pair.begin(), jobs_pair.end(), compare);
    while(!jobs_pair.empty()) {
        for(int i = 0; i < jobs_pair.size(); i ++) {
            if(jobs_pair[i].first <= start_time) {
                start_time += jobs_pair[i].second;
                duration += (start_time - jobs_pair[i].first);
                jobs_pair.erase(jobs_pair.begin() + i);
                break;
            }
            if(i == jobs_pair.size() - 1)
                start_time ++;
        }
    }
    answer = duration / jobs.size();
    return answer;
}