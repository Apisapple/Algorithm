#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> First_answer = {1, 2, 3, 4, 5};
    vector<int> Second_answer = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> Third_answer = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int First = 0;
    int Second = 0;
    int Third = 0;
    int Size = answers.size();
    int First_Count = 0;
    int Second_Count = 0;
    int Third_Count = 0;
    for (int i = 0; i < Size; i++)
    {
        First = i % 5;
        Second = i % 8;
        Third = i % 10;
        if (answers[i] == First_answer[First])
            First_Count++;
        if (answers[i] == Second_answer[Second])
            Second_Count++;
        if (answers[i] == Third_answer[Third])
            Third_Count++;
    }

    int MAX = max(First_Count, max(Second_Count, Third_Count));

    if (MAX == First_Count)
        answer.push_back(1);
    if (MAX == Second_Count)
        answer.push_back(2);
    if (MAX == Third_Count)
        answer.push_back(3);

    return answer;
}