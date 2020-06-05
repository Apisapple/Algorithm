#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    vector<int> Sub_array;
    int Size = commands.size();
    for (int i = 0; i < Size; i++)
    {
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            Sub_array.push_back(array[j]);
        }
        sort(Sub_array.begin(), Sub_array.end());
        answer.push_back(Sub_array[commands[i][2] - 1]);
        Sub_array.clear();
    }
    return answer;
}