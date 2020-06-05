#include <string>
#include <vector>

using namespace std;

// 전체 학생의 수 n
// 도난당한 학생들의 번호가 담긴 배열 lost,
// 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve
// return 값은 수업을 들을 수 있는 학생의 최댓값

// 제한사항
// 전체 학생의 수는 2명 이상 30명 이하
// 체육복을 도난당한 학생의 수는 1명 이상 n명 이하 중복되는 번호 x
// 여벌의 체육복을 가져온 학생의 수는 1명 이상 n명 이하이고 중복 번호 x
// 여벌 체육복이 있는 학생만 다른 학생에게 체육복을 빌려줄 수 있음
// 여벌 체육복을 가져온 학생이 체육복을 도난 당했을 수 있음. 이때 학생은 하나만 도난 당했다고 가정
// 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없음

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;
    vector<int> temp(n, 1);

    // 여유 체육복을 가지고 있는 사람 확인
    for (int i = 0; i < reserve.size(); i++)
    {
        temp[reserve[i] - 1]++;
    }

    //  체육복을 도난당한 사람들을 확인
    for (int i = 0; i < lost.size(); i++)
    {
        temp[lost[i] - 1]--;
    }

    //  체육복 빌려주기
    for (int i = 0; i < n; i++)
    {
        // 체육복이 도난당해 없을 때
        if (temp[i] == 0)
        {
            // 주변 사람중에 여유분이 없는 경우
            if (temp[i - 1] != 2 && temp[i + 1] != 2)
            {
                answer--;
            }
            // 주변 사람중에 여유분이 있는 경우
            else
            {
                if (temp[i - 1] == 2)
                {
                    temp[i - 1]--;
                }
                else if (temp[i + 1] == 2)
                {
                    temp[i + 1]--;
                }
            }
        }
    }

    return answer;
}