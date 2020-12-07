#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

void DFS(int size, int index, vector<int> answer_list, vector<int> number_list, vector<bool> visited) {
    if(size == M) {
        for(int i = 0; i < answer_list.size(); i++) {
            // cout << answer_list[i] << " ";
            printf("%d ", answer_list[i]);
        }
        // cout << endl;
        printf("\n");
        return;
    }
    for(int i = 0; i < N; i ++) {
        if(!visited[i]) {
            visited[i] = true;
            answer_list.push_back(number_list[i]);
            DFS(size + 1, i + 1, answer_list, number_list, visited);
            answer_list.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    vector <int> answer_list;
    vector <int> number_list(N);
    vector <bool> visited(N, false);

    // 숫자 입력
    for(int i = 0; i < N; i++) {
        scanf("%d", &number_list[i]);
    }
    sort(number_list.begin(), number_list.end());
    //  깊이 우선 탐색
    for(int i = 0; i < N; i++) {
        visited[i] = true;
        answer_list.push_back(number_list[i]);
        DFS(1, i + 1, answer_list, number_list, visited);
        answer_list.pop_back();
        visited[i] = false;
    }
    return 0;
}