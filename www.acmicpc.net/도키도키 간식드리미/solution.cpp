#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    queue<int> numberList;
    stack<int> temp;
    int inputSize = 0;
    cin >> inputSize;

    for(int i = 0; i < inputSize; i++) {
        int number = 0;
        cin >> number;
        numberList.push(number);
    }
    
    int index = 1;
    while(!numberList.empty()) {
        int current = numberList.front();
        if(current == index) {
            index ++;
            numberList.pop();
        } else {
            if(!temp.empty() && temp.top() == index) {
                temp.pop();
                index ++;
            } else {
                temp.push(current);
                numberList.pop();
            }
        }
    }

    while(!temp.empty()) {
        int current = temp.top();
        temp.pop();
        if(current != index) {
            cout << "Sad" << endl;
            return 0;
        }
        index ++;
    }
    cout << "Nice" << endl;
    return 0;
}