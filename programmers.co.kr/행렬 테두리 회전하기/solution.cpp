#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MAX 100

vector<vector<int>> arr(MAX + 1, vector<int>(MAX + 1 ,0));
vector<int> answer;

void rotateBoard(int rows, int columns, vector<vector<int>> & queries) {
    for(vector<int> query : queries) {
        vector<vector<int>> tempArr(arr);
        int minValue = MAX * MAX;
        
        for(int i = query[1] + 1; i <= query[3]; i++) {
            tempArr[query[0]][i] = arr[query[0]][i - 1];
            minValue = min(minValue, tempArr[query[0]][i]);
        }

        for (int j = query[0] + 1; j <= query[2]; j++) {
            tempArr[j][query[3]] = arr[j - 1][query[3]];
            minValue = min(minValue, tempArr[j][query[3]]);
        }      

        for (int i = query[3] - 1; i >= query[1]; i--) {
            tempArr[query[2]][i] = arr[query[2]][i + 1];
            minValue = min(minValue, tempArr[query[2]][i]);
        }

        for (int j = query[2] - 1; j >= query[0]; j--) {
            tempArr[j][query[1]] = arr[j + 1][query[1]];
            minValue = min(minValue, tempArr[j][query[1]]);
        }
        arr = tempArr;
        answer.push_back(minValue);
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int number = 1;
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            arr[i][j] = number ++;
        }
    }
    
    rotateBoard(rows, columns, queries);
    
    return answer;
}