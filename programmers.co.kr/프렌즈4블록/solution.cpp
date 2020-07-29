#include <string>
#include <vector>

using namespace std;



int solution(int m, int n, vector<string> board) {
    vector <string> tempBoard;
    int answer = 0;
    int height = board.size();
    int width = board[0].size();
    
    while(1) {
        bool flag = true;
        vector <vector<bool>> visit(height, vector<bool> (width, false));
        for(int i = 0 ; i < height - 1; i++) { // 완전 탐색
            for(int j = 0 ; j < width - 1; j++) {
                char pivot = board[i][j];
                if(board[i][j] != ' ' && board[i + 1][j] == pivot && board[i][j + 1] == pivot && board[i + 1][j + 1] == pivot) {
                    flag = false;
                    visit[i][j] = true;
                    visit[i + 1][j] = true;
                    visit[i][j + 1] = true;
                    visit[i + 1][j + 1] = true; 
                } else if(board[i][j] == ' ')
                    continue;
            }
        }

        for(int i = 0; i < height; i ++) {
            for(int j = 0; j < width; j ++) {
                if(visit[i][j]) {
                    answer ++;
                    for(int k = i - 1; 0 <= k; k --) {
                        board[k + 1][j] = board[k][j];
                        board[k][j] = ' ';
                    }
                }
            }
        }
        if(flag) 
            break;
    }
    return answer;
}