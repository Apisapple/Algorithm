#include <algorithm>
#include <string>
#include <vector>

using namespace std;
struct Boxer {
    int index = 0;
    int weight = 0;
    int winCntHeavier = 0;
    double winRate = 0;
};
bool compare(Boxer a, Boxer b) {
    if(a.winRate > b.winRate)
        return true;
    else if(a.winRate == b.winRate) {
        if(a.winCntHeavier > b.winCntHeavier)
            return true;
        else if(a.winCntHeavier == b.winCntHeavier) {
            if(a.weight > b.weight)
                return true;
            else if(a.weight == b.weight && a.index < b.index)
                return true;
        }
    }
    return false;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    
    vector<Boxer> boxerList;
    
    //Boxer정보 입력
    for(int i = 0; i < head2head.size(); i++) {
        double win = 0;
        double totalMatches = 0;
        int winCntHeavier = 0;
        for(int j = 0; j < head2head[i].size(); j++) {
            if(head2head[i][j] == 'N')
                continue;
            else if(head2head[i][j] == 'W') {
                win++;
                if(weights[i] < weights[j])
                    winCntHeavier ++;
            } 
            totalMatches++;                
        }
        boxerList.push_back({i + 1, weights[i], winCntHeavier, totalMatches ? win / totalMatches : 0});
    }
    
    sort(boxerList.begin(), boxerList.end(), compare);
    
    for(Boxer boxer : boxerList) {
        answer.push_back(boxer.index);
    }
    return answer;
}