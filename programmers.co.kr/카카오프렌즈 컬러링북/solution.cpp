#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    queue <pair <int, int>> temp;
    for(int i = 0; i < m; i ++){
        for(int j = 0 ; j < n; j++){
            /* 색칠 X, 혹은 방문한 곳은 continue */
            if(picture[i][j] <= 0) 
                continue;
            int color = picture[i][j];
            picture[i][j] = -1;
            int areaSize = 1;
            temp.push(make_pair(i,j));
            while(!temp.empty()){
                int current_x = temp.front().first;
                int current_y = temp.front().second;
                temp.pop();
                for(int k = 0; k < 4; k++){
                    int next_x = current_x + dx[k];
                    int next_y = current_y + dy[k];
                    if((next_x >= 0) && (next_y >= 0) && (next_x < m) && (next_y < n) && (picture[next_x][next_y] == color)){
                        picture[next_x][next_y] = -1;
                        areaSize++;
                        temp.push(make_pair(next_x, next_y));
                    }
                }
            }
            if(max_size_of_one_area < areaSize) 
                max_size_of_one_area = areaSize;
            number_of_area++;
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}