#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N, M;
    vector<string>::iterator iter;     // Group의 이름을 담을 변수
    string gName;                      // Group : Member vector 형태의 map
    map<string, vector<string>> group; // member 이름 : Group 이름 형태의 map
    map<string, string> member;
    cin >> N;
    cin >> M; // Group, Member의 이름을 키로 하는 map을 만드는 과정
    for (int i = 0; i < N; i++)
    {
        int num;
        string name;
        vector<string> mem;
        cin >> gName >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> name;
            mem.push_back(name);
            member.insert(make_pair(name, gName));
        }
        sort(mem.begin(), mem.end());
        group.insert(make_pair(gName, mem));
    } // 문제 타입(그룹의 이름이 주어졌는지, 멤버의 이름이 주어졌는지)에 따라 분리해서 출력
    for (int i = 0; i < M; i++)
    {
        string p;
        int type;
        cin >> p >> type;
        if (type == 1)
        {
            cout << member[p] << endl;
        }
        else
        {
            for (iter = group[p].begin(); iter != group[p].end(); iter++)
            {
                cout << *iter << endl;
            }
        }
    }
    return 0;
}
