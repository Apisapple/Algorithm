#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/* 제한사항
모든 공항은 알파벳 대문자 3글자로 이루어집니다.
주어진 공항 수는 3개 이상 10,000개 이하입니다.
tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
주어진 항공권은 모두 사용해야 합니다.
만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
모든 도시를 방문할 수 없는 경우는 주어지지 않습니다. */
int max_count = 0;
vector<string> answer;

void dfs(string start_city, vector<pair<string, string>> &ticket_pair, vector<string> &temp, vector<bool> &visit_city, int count ) {
    temp.push_back(start_city);
    
    if(max_count < count) {
        max_count = count;
        answer = temp;
    }

    for(int i = 0; i < ticket_pair.size(); i++) {
        if(start_city == ticket_pair[i].first && !visit_city[i]) {
            visit_city[i] = true;
            dfs(ticket_pair[i].second , ticket_pair, temp, visit_city, count + 1);
            visit_city[i] = false;
        }
    }
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> temp;
    vector<bool> visit_city(tickets.size(), false);
    vector<pair<string, string>> tickets_pair;
    for(int i = 0; i < tickets.size(); i++) {
        tickets_pair.push_back(make_pair(tickets[i][0], tickets[i][1]));
    }
    sort(tickets_pair.begin(), tickets_pair.end());
    dfs("ICN", tickets_pair, temp, visit_city, 0);
    return answer;
}