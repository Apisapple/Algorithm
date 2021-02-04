#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector <int> maxCnt(30, 0);
vector <string> menu[30][30];
map <string, int> cnt;

void calc(string temp, int index, string mkstring) {
    if(mkstring.size() > 1) {
        cnt[mkstring] ++;
        maxCnt[mkstring.size()] = max(maxCnt[mkstring.size()], cnt[mkstring]);
        menu[mkstring.size()][cnt[mkstring]].push_back(mkstring);
    }

    for(int i = index; i < temp.size(); i++) {
        mkstring.push_back(temp[i]);
        calc(temp, i + 1, mkstring);
        mkstring.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(string& temp : orders) {
        sort(temp.begin(), temp.end());
        calc(temp, 0, "");
    }

    for(int i : course) {
         if(maxCnt[i]>1)
            for(string s:menu[i][maxCnt[i]])
                answer.push_back(s);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
