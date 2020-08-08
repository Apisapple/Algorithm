#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    
    int pivot = routes[0][1];
    for(int i = 1 ; i < routes.size(); i++) {
        if(pivot > routes[i][1]) {
            pivot = routes[i][1];
        }
        if(pivot < routes[i][0]) {
            answer ++;
            pivot = routes[i + 1][1];
        }
    }
    return answer;
}