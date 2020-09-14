#include <iostream>
#include <vector>

using namespace std;

#define MAX 10001

vector<bool> visit(MAX, false);
int temp;

void DFS(int index, int computers_count, vector <vector <int> > board) {
    visit[index] = true;
    for(int i = 1; i <= computers_count; i++) {
        if(!visit[i] && board[index][i] == 1){
            temp++;
            DFS(i, computers_count, board);
        }
    }
}

int main() {
    int computers_count;
    int computers_pair;
    int first, second;
    temp = 0;
    cin >> computers_count;
    cin >> computers_pair;
    vector <vector <int> > board(computers_count + 1, vector<int>(computers_count + 1, 0));
    for(int i = 0; i < computers_pair; i++) {
        cin >> first >> second;
        board[first][second] = 1;
        board[second][first] = 1;
    }
    DFS(1, computers_count, board);
    cout << temp << endl;
    return 0;
}