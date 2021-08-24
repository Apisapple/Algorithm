#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MAX 6

int getRank(int match_cnt) {
    if(match_cnt < 2)
        return MAX;
    
    return 7 - match_cnt;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int zeroCnt = 0, cnt = 0;
    vector<int> answer;
    
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    for(int i = 0; i < MAX; i++) {
        if(lottos[i] == 0)
            zeroCnt ++;
        else
            break;
    }
    int temp = zeroCnt;
    for(int i = 0; i < MAX; i++) {
        if(zeroCnt == MAX)
            break;
        for(int j = zeroCnt; j < MAX; j++) {
            if(win_nums[i] == lottos[j]) {
                cnt ++;
            }
        }
    }
    
    answer.push_back(getRank(cnt + zeroCnt));
    answer.push_back(getRank(cnt));
    return answer;
}