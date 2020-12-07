#include <iostream>
#include <vector>

using namespace std;

int N, M;

void DFS(int size, int index, vector<int> number_list, vector<int> answer_list, vector<bool> &visited_list) {
    // 길이를 모두 만족하면 출력
    if(size == M) {
        for(int i = 0; i < answer_list.size(); i++) {
            cout << answer_list[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = index; i < N; i++) {
        if(visited_list[i] == false) {
            visited_list[i] = true;
            answer_list.push_back(number_list[i]);
            DFS(size + 1, i + 1, number_list, answer_list, visited_list);
            answer_list.pop_back();
            visited_list[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    vector<int> answer_list;
    vector<int> number_list(N);
    vector<bool> visited_list(N, false);

    for(int i = 0; i < N; i++) {
        number_list[i] = i + 1;
    }

    // 깊이우선 탐색 시작
    for(int i = 0; i < N; i++) {
        visited_list[i] = true;
        answer_list.push_back(number_list[i]);
        DFS(1, i + 1, number_list, answer_list, visited_list);
        answer_list.pop_back();
    }
    return 0;
}