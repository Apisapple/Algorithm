#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector <bool> member(20, false);
int team_dif = 123456789;
int N;

void teamDifCalc(vector <vector<int>> &board, int index, int dept) {
    vector <int> start_team;
    vector <int> link_team;
    int start_team_score = 0;
    int link_team_score = 0;

    if(dept == (N / 2)) {
        // 팀 생성
        for(int i = 0; i < N; i++) {
            if(member[i])
                start_team.push_back(i);
            else
                link_team.push_back(i);
        }
        for(int i = 0; i < (N / 2); i ++) {
            for(int j = 0; j < (N / 2); j++) {
                start_team_score += board[start_team[i]][start_team[j]];
                link_team_score += board[link_team[i]][link_team[j]];
            }
        }
        if(abs(start_team_score - link_team_score) < team_dif)
            team_dif = abs(start_team_score - link_team_score);

        return;
    }
    //  팀 나누기
    for(int i = index; i < N; i++) {
        if(member[i]) {
            continue;
        } else {
            member[i] = true;
            teamDifCalc(board, i, dept + 1);
            member[i] = false;
        }
    }
}

int main() {
    cin >> N;
    vector <vector <int>> board(N, vector<int> (N, 0));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];

    teamDifCalc(board, 0, 0);
    cout << team_dif << endl;
    return 0;
}