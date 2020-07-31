#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0)
        return cities.size() * 5;

    vector <string> cache;
    int answer = 0;
    for(string city : cities) {
        bool flag = true;
        /* 대소문자 상관 X */
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        /* hit */
        for(int i = 0; i < cache.size(); i++) {
            if(cache[i] == city) {
                cache.erase(cache.begin() + i);
                cache.push_back(city);
                answer ++;
                flag = false;
                break;
            }
        }
        if(flag) {
            if(cacheSize <= cache.size()) {
                cache.erase(cache.begin());
            }
            cache.push_back(city);
            answer += 5;
        }
    }
    return answer;
}