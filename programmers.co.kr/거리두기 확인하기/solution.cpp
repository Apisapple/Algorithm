#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define PLACE_SIZE 5

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool getDistanceInfo(int x, int y, vector<string> &place) {
    vector<vector<bool>> visited(PLACE_SIZE, vector<bool>(PLACE_SIZE, false));
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(x, y), 0));
    visited[x][y] = true;
    
    while(!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int cnt = que.front().second;
        que.pop();
        
        if(cnt == 2)
            continue;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0 <= nx && nx < PLACE_SIZE && 0 <= ny && ny < PLACE_SIZE) {
                if(!visited[nx][ny]) {
                    if(place[nx][ny] == 'O') {
                        visited[nx][ny] = true;
                        que.push(make_pair(make_pair(nx, ny), cnt + 1));
                    } else if (place[nx][ny] == 'P') {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool getResult(vector<string> place) {
    for(int i = 0; i < PLACE_SIZE; i++) {
        for(int j = 0; j < PLACE_SIZE; j++) {
            if(place[i][j] == 'P') {
                if(!getDistanceInfo(i, j, place)) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto place : places) {
        if(getResult(place))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}