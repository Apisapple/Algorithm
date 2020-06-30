#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    /* 모든 사각형의 합은 넓이와 같다 */
    int Area = brown + yellow;
    /* 서로 다른 색의 사각형의 테두리를 둘러야 하기 때문에 높이는 무조건 3 이상 */
    for (int height = 3; height < Area / 2; height ++){
        int width = Area / height;
        /* 각각의 갯수 조건을 모두 만족하는 경우 */
        if(yellow == (height - 2) * (width - 2) && brown == Area - yellow){
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }
    return answer;
}