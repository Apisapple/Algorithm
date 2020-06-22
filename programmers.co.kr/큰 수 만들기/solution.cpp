#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    stack <char> tempList;
    string answer = "";
    /* 답이 되는 숫자의 크기 */
    int answerSize = number.length() - k;
   /*  가장 큰 수를 만들어야 하므로 크기가 앞에 값이 큰 수일 경우 제외
    너무 많이 수를 제외시켜버릴 수 있으므로 k를 통해 버리는 수를 제한 */
    for(int i = 0 ; i < number.length(); i++){
        int current = number[i];
        while(!tempList.empty() && k > 0){
            int top = tempList.top();
            if(current <= top)
                break;
            tempList.pop();
            k--;
        }
        tempList.push(current);
    }

    /* k = 3 number = 100000000 같은 경우가 있을 수 있으므로 크기를 맞춰준다. */
    while(tempList.size() != answerSize){
        tempList.pop();
    }
    /* 답안 작성 */
    while(!tempList.empty()){
        char value = tempList.top();
        answer = value + answer;
        tempList.pop();
    }
    return answer;
}