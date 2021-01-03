#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector <int> clothesName(30 , 0);
    vector <bool> clothesKind(30, false);

    /* 옷의 종류에 따른 갯수 세기 */
    for(int i = 0; i < clothes.size(); i ++){
        for(int j = i; j < clothes.size(); j++){
            if(clothesKind[j])
                continue;
            if(clothes[i][1] == clothes[j][1]){
                clothesName[i] ++;
                clothesKind[j] = true;
            }
        }
    }

    for(int i = 0; i < clothesName.size(); i++){
        if(clothesName[i] != 0)
            answer *= (clothesName[i] + 1);
    }
    return answer - 1;
}

int main() {
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        int clothes_cnt;
        cin >> clothes_cnt;
        vector<vector<string>> clothes(clothes_cnt, vector<string>(2));
        // 옷 정보 입력
        for(int j = 0; j < clothes_cnt; j++) {
            cin >> clothes[j][0] >> clothes[j][1];
        }

        cout << solution(clothes) << endl;
    }

    return 0;
}