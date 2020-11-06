#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> pyramid (n, vector<int>(n, 0));
    int direction = 0;
    int number = 1;
    int x = 0, y = 0;
//     피라미드 채우기
    for(int i = 0; i < n; i++) {
        switch(direction){
            case 0:
                for(int j = i; j < n; j++, y++, number++) {
                    pyramid[y][x] = number;
                }
                direction = 1;
                y --;
                x ++;
                break;
            case 1:
                for(int j = i; j < n; j++, x++, number++) {
                    pyramid[y][x] = number;
                }
                direction = 2;
                x -= 2;
                y --;
                break;
            case 2:
                for(int j = i; j < n; j++, x--, y--, number++) {
                    pyramid[y][x] = number;
                }
                direction = 0;
                x ++;
                y += 2;
                break;
        }
    }
    // 정답채우기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            answer.push_back(pyramid[i][j]);
        }
    }
    return answer;
}