#include <iostream>
#include <vector>

using namespace std;

int main() {
    int iceCream, doNotColabo;
    int answer = 0;
    cin >> iceCream >> doNotColabo;
    vector <vector <bool> > colaboration(iceCream + 1, vector <bool> (iceCream + 1, false));
    // 맛없는 조합들 입력
    for(int i = 0; i < doNotColabo; i++) {
        int first, second;
        cin >> first >> second;
        colaboration[first][second] = true;
        colaboration[second][first] = true;
    }
    
    for(int i = 1; i <= iceCream; i++) {
        for(int j = i + 1; j <= iceCream; j++) {
            if(colaboration[i][j])
                continue;
            for(int k = j + 1; k <= iceCream; k++) {
                if(colaboration[i][k] || colaboration[j][k])
                    continue;
                else
                    answer ++;
            }
        }
    }

    cout << answer << endl;
}