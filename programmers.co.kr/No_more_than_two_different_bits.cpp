#include <string>
#include <vector>

using namespace std;

long long get_answer_value(long long number) {

    if (number % 2 == 0) {
        return number + 1;
    } else {
        long long bit = 1;

        while (true) {
            if((number & bit) == 0) {
                break;
            }
            bit = bit << 1;
        }
        bit = bit >> 1;
        return number + bit;
    }
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (auto number : numbers) {
        answer.push_back(get_answer_value(number));
    }
    return answer;
}
