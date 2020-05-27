#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int pickup(vector<vector<int>> &board, int width, int height){
    if(height >= board.size())
        return 0;
    if(board[height][width] != 0)
    {
        int temp = board[height][width];
        board[height][width] = 0;
        return temp;
    }
    else
    {
        return pickup(board, width, height + 1);
    }
}
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack <int> temp;
  
    // 움직이는 위치
    for(int i = 0 ; i < moves.size(); i++){
        int value = pickup(board, moves[i] - 1, 0);
        if(value != 0){
            if(temp.size() == 0){
                temp.push(value);
            }else if(temp.top() == value){
                answer += 2;
                temp.pop();
            }else{
                temp.push(value);
            }
        }
    }
    return answer;
}