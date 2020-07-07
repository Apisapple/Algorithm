#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> arr, int index){

}
int solution(vector<vector<int> > land)
{
    vector<int> arr;
    int answer = 0;

    vector<vector<int>> temp = land;
    for(int i = 1 ; i < temp.size(); i ++){
        for(int j = 0 ; j < temp[i].size(); j++){
            for(int k = 0; k < temp[i].size();)
            temp[i][j] = findMax(temp, j);
        }
    }
    return answer;
}