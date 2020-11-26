#include <iostream>
#include <vector>

using namespace std;

void DFS(int number_count, vector<int> &number_list, vector<int> &answer_list, int index) {
    int answer_size = answer_list.size();
    // 최대 6개의 값을 가지도록 함
    if(answer_size > 6)
        return;

    if(answer_size == 6) {
        for(int i = 0; i < 6; i++) 
            cout << number_list[answer_list[i]] << " ";
        cout << "\n";
        return;
    }
    for(int i = index + 1; i < number_count; i++) {
        if(answer_size + (number_count - i) < 6)
            return;
        answer_list.push_back(i);
        DFS(number_count, number_list, answer_list, i);
        answer_list.pop_back();
    }
}

int main() {
    while (true)
    {
        int number_count;
        cin >> number_count;
        if(number_count == 0)
            return 0;
        
        vector<int> number_list(number_count, 0);
        vector<int> answer_list;
        for(int i = 0; i < number_count; i++) {
            cin >> number_list[i];
        }
        // DFS 시작
        for(int i = 0 ; i < number_count; i++) {
            answer_list.push_back(i);
            DFS(number_count, number_list, answer_list, i);
            answer_list.pop_back();
        }
        cout << "\n";
    }

    
    return 0;
}