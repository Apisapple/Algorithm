#include <vector>
#include <string>
using namespace std;

struct dirs_street {
    bool UP = false;
    bool DOWN = false;
    bool LEFT = false;
    bool RIGHT = false;
};
dirs_street board[11][11];
int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;
    
    for(int i = 0; i < dirs.length(); i++) {
        switch (dirs[i]) {
        case 'U':
            if(y == 10)
                break;
            if(!board[x][y + 1].DOWN) {
                board[x][y].UP = true;
                board[x][y + 1].DOWN = true;
                answer ++;
            }
            y ++;
            break;
        case 'D':
            if(y == 0)
                break;

            if(!board[x][y - 1].UP) {
                board[x][y].DOWN = true;
                board[x][y - 1].UP = true;
                answer ++;
            }
            y --;
            break;

        case 'R':
            if(x == 10)
                break;

            if(!board[x + 1][y].LEFT) {
                board[x][y].RIGHT = true;
                board[x + 1][y].LEFT = true;
                answer ++;
            }
            x ++;
            break;
        
        case 'L':
            if(x == 0)
                break;
            if(!board[x - 1][y].RIGHT) {
                board[x][y].LEFT = true;
                board[x - 1][y].RIGHT = true;
                answer ++;
            }
            x --;
            break;
        }
    }
    return answer;
}