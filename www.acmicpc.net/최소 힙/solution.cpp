#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    priority_queue <int, vector<int>, greater<int> > pq;
    int calCount = 0;
    // 연산 횟수 입력
    scanf("%d", &calCount);
    for(int i = 0; i < calCount; i++) {
        int number;
        scanf("%d", &number);
        switch (number)
        {
        case 0:
            if(pq.empty()) {
                printf("%d\n", 0);
            } else {
                int temp = pq.top();
                printf("%d\n" , temp);
                pq.pop();
            }
            break;
        default:
            pq.push(number);
            break;
        }
    }

    return 0;
}