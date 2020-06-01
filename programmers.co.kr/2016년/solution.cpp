#include <string>
#include <vector>

using namespace std;

int calender[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string Days[7] = {"FRI","SAT","SUN", "MON","TUE","WED","THU"};

string solution(int a, int b)
{
    string answer = "";
    int count = 0;
    for(int i = 0; i < a - 1; i++){
        count += calender[i];
    }
    count += (b - 1);
    return Days[count % 7];
}