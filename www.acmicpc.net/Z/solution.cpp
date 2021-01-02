#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 15

using namespace std;

pair <int, int> mv[4] = { {0, 0}, {0, 1}, {1, 0}, {1, 1}};
int N = 0, r = 0, c = 0;
int answer = 0;

void solve(int x_index, int y_index, int board_size) {
    if(board_size == 2) {   // 만약 board의 사이즈가 2 (가장 작은 사이즈) 라면..
        if(r == x_index && c == y_index) {
            cout << answer << endl;
            return;
        } else if(r == x_index && c == y_index + 1) {
            cout << answer + 1 << endl;
            return;
        } else if(r == x_index + 1 && c == y_index) {
            cout << answer + 2<< endl;
            return;
        } else if(r == x_index + 1 && c == y_index + 1) {
            cout << answer + 3 << endl;
            return;
        }
        answer += 4;
    } else { // board의 사이즈가 2가 아니라면...
        int next_size = (board_size >> 1);
        for(int i = 0; i < 4; i++) {
            int nx = x_index + mv[i].first * next_size;
            int ny = y_index + mv[i].second * next_size;
            if(nx <= r && r < nx + next_size && ny <= c && c < ny + next_size) {
                solve(nx, ny, next_size);
            } else {
                answer += next_size * next_size;
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> r >> c;
    solve(0, 0, 1 << N);
    return 0;
}