#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxChoice(int a, int b, int c){
    return max(a, max(b, c));
}

int solution(vector<vector<int> > land)
{
    vector<vector<int>> temp = land;
    vector<int> arr;
    int answer = 0;
    int size = temp.size() - 1;
    for(int i = 1; i < temp.size(); i++) {
        temp[i][0] += maxChoice(temp[i-1][1], temp[i-1][2], temp[i-1][3]);
        temp[i][1] += maxChoice(temp[i-1][0], temp[i-1][2], temp[i-1][3]);
        temp[i][2] += maxChoice(temp[i-1][1], temp[i-1][0], temp[i-1][3]);
        temp[i][3] += maxChoice(temp[i-1][1], temp[i-1][2], temp[i-1][0]);
    }
    answer = max(temp[size][0],maxChoice(temp[size][1], temp[size][2], temp[size][3]));
    return answer;
}