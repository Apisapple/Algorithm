#include <string>
#include <vector>

using namespace std;

// const unsigned char p[16] ={0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1};
const unsigned char p[16] ={0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80};

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    vector<int> temp(n);
/*  보물지도를 나타내기 위한 비트연산
    1 | 1 = 1
    1 | 0 = 1
    0 | 1 = 1
    0 | 0 = 0 */
    for(int i = 0; i < n; i++){
        temp[i] = arr1[i] | arr2[i];
    }
    // 각 비트를 비교하여 '#' 또는 ' '를 입력
    for(int i = 0; i < n; i++){
        int index = 1 << n - 1;
        for(int j = 0; j < n; j++){
            if(temp[i] & (index >> j)){
                answer[i].push_back('#');
            }else{
                answer.[i].push_back(' ');
            }
        }
    }

    return answer;
}