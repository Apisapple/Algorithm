#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 20
#define DICE 6

vector<vector<int>> board(MAX + 1, vector<int>(MAX + 1, 0));
vector<int> diceNum(DICE, 0);
int diceIndex[DICE] = {1, 5, 3, 2, 4, 6};

int row = 0, col = 0;
int dice_x = 0, dice_y = 0;
int commendCnt = 0;
void init() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

bool changeDice(int move) {
    bool result = false;
    switch (move)
    {
    case 1:
        if(dice_y + 1 < row) {
            dice_y += 1;
            result = true;
        }
        break;

    case 2:
        if(dice_y - 1 >= 0) {
            dice_y -= 1;
            result = true;
        }
        break;

    case 3:
        if(dice_x - 1 >= 0) {
            dice_x -= 1;
            result = true;
        }
        break;

    case 4:
        if(dice_x + 1 < col) {
            dice_x += 1;
            result = true;
        }
        break;
    
    default:
        break;
    }

    return result;
}
void changeDiceIndex(int move) {
    int subNumber = diceIndex[0];

    switch (move) {
            // 동
        case 1:
            diceIndex[0] = diceIndex[4];
            diceIndex[4] = diceIndex[5];
            diceIndex[5] = diceIndex[2];
            diceIndex[2] = subNumber;
            break;
            // 서
        case 2:
            diceIndex[0] = diceIndex[2];
            diceIndex[2] = diceIndex[5];
            diceIndex[5] = diceIndex[4];
            diceIndex[4] = subNumber;
            break;
            // 북
        case 3:
            diceIndex[0] = diceIndex[1];
            diceIndex[1] = diceIndex[5];
            diceIndex[5] = diceIndex[3];
            diceIndex[3] = subNumber;
            break;
            // 남
        case 4:
            diceIndex[0] = diceIndex[3];
            diceIndex[3] = diceIndex[5];
            diceIndex[5] = diceIndex[1];
            diceIndex[1] = subNumber;
            break;
        default:
            printf("error!!");
            break;
    }
}

bool diceRoll(int move) {
    if(!changeDice(move)) {
        return false;
    }

    changeDiceIndex(move);

    if(board[dice_x][dice_y] == 0) {
        board[dice_x][dice_y] = diceNum[diceIndex[DICE - 1] - 1];
    } else {
        diceNum[diceIndex[DICE - 1] - 1] = board[dice_x][dice_y];
        board[dice_x][dice_y] = 0;
    }

    return true;
}


int main(int argc, char const *argv[])
{
    cin >> col >> row >> dice_x >> dice_y >> commendCnt;

    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            cin >> board[i][j];
        }
    }

    int move = 0;
    for(int i = 0; i < commendCnt; i++) {
        cin >> move;
        if(diceRoll(move)) {
            cout << diceNum[diceIndex[0] - 1] << '\n';
        }

    }

    return 0;
}
