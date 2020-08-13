#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> temp = triangle;
    
    for(int i = 1; i < triangle.size(); i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
               temp[i][j] = temp[i -1][j] + triangle[i][j];
            } else if(i == j) {
                temp[i][j] = temp[i - 1][j - 1] + triangle[i][j];
            } else {
                temp[i][j] = max(temp[i - 1][j - 1] + triangle[i][j], temp[i - 1][j] + triangle[i][j] );
            }
            if(i == triangle.size() - 1) {
                answer = max(answer , temp[i][j]);
            }
        }
    }
    return answer;
}