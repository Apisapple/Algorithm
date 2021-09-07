#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    if(a.second == b.second) 
        return a.first < b.first;  
    else 
        return a.second > b.second; 
}


string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    vector<pair<string, int>> scores;
    string answer = "";
    
    for(string row : table) {
        map<string, int> info;
        string jobCategory = "";
        int point = 5, cnt = 0;
        
        istringstream ss(row);
        string temp = "";
        while(getline(ss, temp, ' ')){
            if(cnt == 0){ 
                jobCategory = temp; 
                cnt++; 
            } else {
                info.insert({temp, point --}); 
            }               
        }
        
        point = 0;
        for(int i = 0; i < languages.size(); i++) {
            for(auto mappingInfo : info) {
                if(mappingInfo.first == languages[i]) {
                    point += (preference[i] * mappingInfo.second);
                }
            }
            scores.push_back(make_pair(jobCategory, point));
        }
        
        sort(scores.begin(), scores.end(), compare);
    }
    return scores[0].first;
}