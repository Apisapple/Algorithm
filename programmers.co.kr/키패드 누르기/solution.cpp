#include <string>
#include <vector>
#include <iostream>

using namespace std;

int calDistance(int hand, int number){
    int handRow = hand / 3;
    int handColumn = hand % 3;
    int numberRow = number / 3;
    int numberColumn = number % 3;
    if(numberColumn == 0){
        numberColumn = 3;
    }
    if(handColumn == 0){
        handRow --;
        handColumn = 3;
    }
    return abs(handRow - numberRow) + abs(handColumn - numberColumn);
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftHand = 10;
    int rightHand = 12;
    int number;
    for(int i = 0; i < numbers.size(); i ++){
        /* 왼쪽 라인 */
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer.push_back('L');
            leftHand = numbers[i];
        /* 오른쪽 라인 */
        }else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer.push_back('R');
            rightHand = numbers[i];
        /* 중앙 라인 */
        }else{
            if(numbers[i] == 0){
                numbers[i] = 11;
            }
            int leftDistance = calDistance(leftHand, numbers[i]);
            int rightDistance = calDistance(rightHand, numbers[i]);
            if(leftDistance < rightDistance){
                leftHand = numbers[i];
                answer.push_back('L');
            }else if(leftDistance > rightDistance){
                rightHand = numbers[i];
                answer.push_back('R');
            }else{
                if(hand == "left"){
                    leftHand = numbers[i];
                    answer.push_back('L');
                }else{
                    rightHand = numbers[i];
                    answer.push_back('R');
                }
            }
        }
    }
    return answer;
}