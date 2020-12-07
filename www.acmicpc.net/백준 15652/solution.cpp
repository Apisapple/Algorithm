#include <iostream>
#include <vector>

using namespace std;

int N, M;

void DFS(int size, int index, vector<int> answer_list, vector<int> number_list) {
    if(size == M) {
        for(int i = 0; i < answer_list.size(); i++) {
            cout << answer_list[i]  << " ";
        }
        cout << endl;
        return;
    }
    for(int i = index; i < N; i++) {
        answer_list.push_back(number_list[i]);
        DFS(size + 1, i, answer_list, number_list);
        answer_list.pop_back();
    }
}

int main() {
    cin >> N >> M;
    vector <int> answer_list;
    vector <int> number_list(N);
    for(int i = 0; i < N; i++) {
        number_list[i] = i + 1;
    }
    // 깊이 우선 탐색
    for(int i = 0; i < N; i++) {
        answer_list.push_back(number_list[i]);
        DFS(1, i, answer_list, number_list);
        answer_list.pop_back();
    }
    return 0;
}