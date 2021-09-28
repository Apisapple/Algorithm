#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer(enter.size(), 0);
    set<int> meeting_room;
    map<pair<int, int>, bool> visited;
    int enter_idx = 0, leave_idx = 0;
    
    while(leave_idx < enter.size()) {
        
        // meeting room에 있는지 찾기
        while(meeting_room.find(leave[leave_idx]) == meeting_room.end()) {
            // 나가는 사람이 아닌 경우 meeting room에 입장
            meeting_room.insert(enter[enter_idx]);
            enter_idx ++;
            
            for(int person : meeting_room) {
                visited[{person, enter[enter_idx - 1]}] = true;
                visited[{enter[enter_idx - 1], person}] = true;
            }
        }
        
        while(leave_idx < enter.size() && meeting_room.find(leave[leave_idx]) != meeting_room.end()) {
            meeting_room.erase(leave[leave_idx ++]);
        }
    }
    
    for (int i = 0; i < enter.size(); i++) { 
        int cnt = 0; 
        for (int j = 0; j < enter.size(); j++) { 
            if (i == j)
                continue; 

            if (visited.count({ enter[i], enter[j] })) {
                cnt++; 
            } 
        } 
        answer[enter[i] - 1] = cnt; 
    }

    return answer;
}