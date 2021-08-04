#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_WIDTH 100
#define MAX_BLOCK_NUMBER 7

int widthSize = 0, blockNumber= 0, result = 0;
vector<int> tetrisInfo(MAX_WIDTH + 1, 0);
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

void getCountOne() {
    result = result + widthSize;
    for(int i = 0; i < widthSize - 3; i++) {
        if( tetrisInfo[i] == tetrisInfo[i + 1] &&
            tetrisInfo[i + 1] == tetrisInfo[i + 2] &&
            tetrisInfo[i + 2] == tetrisInfo[i + 3]) {

            result++;
        }
    }
}

void getCountTwo() {
    for(int i = 0; i < widthSize - 1; i++) {
        if(tetrisInfo[i] == tetrisInfo[i + 1])
            result++;
    }
}

void getCountThree() {
    for(int i = 0; i < widthSize - 2; i++) {
        if( tetrisInfo[i] == tetrisInfo[i + 1] &&
            tetrisInfo[i + 1] == tetrisInfo[i + 2] - 1) {
                result ++;
            }
    }

    for(int i = 0; i < widthSize - 1; i++) {
        if(tetrisInfo[i] == tetrisInfo[i + 1] + 1)
            result ++;
    }
}

void getCountFour() {
    for(int i = 0; i < widthSize - 2; i++) {
        if( tetrisInfo[i] == tetrisInfo[i + 1] + 1 &&
            tetrisInfo[i + 1] == tetrisInfo[i + 2])
                result ++;
    }
    for(int i = 0; i < widthSize - 1; i++) {
        if(tetrisInfo[i] == tetrisInfo[i + 1] - 1)
            result ++;
    }
}

void getCountFive() {
    for(int i = 0; i < widthSize - 2; i++) {
        if( tetrisInfo[i] == tetrisInfo[i + 1] &&
            tetrisInfo[i + 1] == tetrisInfo[i + 2])
                result++;
        
        if( tetrisInfo[i] == tetrisInfo[i + 1] + 1 &&
            tetrisInfo[i + 1] == tetrisInfo[i + 2] - 1)
                result++;
    }

    for(int i = 0; i < widthSize - 1; i++) {
        if(tetrisInfo[i] == tetrisInfo[i + 1] - 1)
            result ++;
        if(tetrisInfo[i] == tetrisInfo[i + 1] + 1)
            result ++;
    }
}

void getCountSix() {
    for(int i = 0; i < widthSize - 2; i++) {
        if( tetrisInfo[i] == tetrisInfo[i + 1] &&
            tetrisInfo[i + 1] == tetrisInfo[i + 2])
                result++;
        if( tetrisInfo[i] == tetrisInfo[i + 1] - 1 &&
            tetrisInfo[i + 1] == tetrisInfo[i + 2])
                result ++;
    }

    for(int i = 0; i < widthSize - 1; i++) {
        if(tetrisInfo[i] == tetrisInfo[i + 1])
            result++;
        if(tetrisInfo[i] == tetrisInfo[i + 1] + 2)
            result++;
    }
}

void getCountSeven() {
    for(int i = 0; i < widthSize - 2; i++) {
        if( tetrisInfo[i] == tetrisInfo[i + 1] &&
            tetrisInfo[i + 1] == tetrisInfo[i + 2])
                result++;
        if( tetrisInfo[i] == tetrisInfo[i + 1] &&
            tetrisInfo[i + 1] == tetrisInfo[i + 2] + 1)
                result++;
    }

    for(int i = 0; i < widthSize - 1; i++) {
        if(tetrisInfo[i] == tetrisInfo[i + 1] - 2)
            result++;
        if(tetrisInfo[i] == tetrisInfo[i + 1])
            result++;
    }
}

int main() {
    initSolution();

    cin >> widthSize >> blockNumber;

    for(int i = 0; i < widthSize; i++) {
        cin >> tetrisInfo[i];
    }

    switch (blockNumber){
        case 1:
            getCountOne();
            break;
        case 2:
            getCountTwo();
            break;

        case 3:
            getCountThree();
            break;

        case 4:
            getCountFour();
            break;

        case 5:
            getCountFive();
            break;

        case 6:
            getCountSix();
            break;

        case 7:
            getCountSeven();
            break;
    }

    cout << result << '\n';
    return 0;
}