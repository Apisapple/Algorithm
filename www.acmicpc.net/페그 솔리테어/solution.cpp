#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

#define MAX_CASE 100

vector<string> arr(5);
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int testCase, result = 0, pin = 0;

void findResult() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            if(arr[i][j] == 'o') {
                for(int p = 0; p < 4; p++) {
                    int nx = j + dx[p];
                    int ny = i + dy[p];

                    if(0 <= nx && 0 <= ny && nx < arr[i].size() && ny < 5 && arr[ny][nx] == 'o') {
                        int dnx = nx + dx[p];
                        int dny = ny + dy[p];

                        if(0 <= dnx && 0 <= dny & dnx < arr[i].size() && dny < 5 && arr[dny][dnx] == '.' ) {
                            arr[dny][dnx] = 'o';
                            arr[ny][nx] = '.';
                            arr[i][j] = '.';
                            findResult();
                            arr[dny][dnx] = '.';
                            arr[ny][nx] = 'o';
                            arr[i][j] = 'o';
                        }
                    }
                }
            }
        }
    }

    int temp = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            if(arr[i][j] == 'o')
                temp++;
        }
    }

    result = min(result, temp);
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);


    cin >> testCase;

    while(testCase --) {
        result = 9;
        pin = 0;
        for(int i = 0; i < 5; i++) {
            cin >> arr[i];
            for(int j = 0; j < arr[i].size(); j ++) {
                if(arr[i][j] == 'o')
                    pin ++;
            }
        }

        findResult();
        cout << result << " " << pin - result << '\n';
    }

    return 0;
}