#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct NODE {
    char left_node;
    char right_node;
};
vector <NODE> arr(27);

// 전위 순회
void PreOrder(char middle) {
    if(middle == '.')
        return;

    cout << middle;
    PreOrder(arr[middle].left_node);
    PreOrder(arr[middle].right_node);
}
//  중위 순회
void MidOrder(char middle) {
    if(middle == '.')
        return;
    MidOrder(arr[middle].left_node);
    cout << middle;
    MidOrder(arr[middle].right_node);
}
// 후위 순회
void LastOrder(char middle) {
    if(middle == '.')
        return;
    LastOrder(arr[middle].left_node);
    LastOrder(arr[middle].right_node);
    cout << middle;
}

int main() {
    int N;
    char a, b, c;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        arr[a].left_node = b;
        arr[a].right_node = c;
    }
    PreOrder('A');
    cout << endl;
    MidOrder('A');
    cout << endl;
    LastOrder('A');
    cout << endl;
    return 0;
}