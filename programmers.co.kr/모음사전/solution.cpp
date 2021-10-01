#include <string>
#include <vector>
#include <map>

using namespace std;

int cnt = 0;
string wordList = "";
int mul[5] = {1, 5, 25, 125, 625};
map<char, int> mappingTable = { {'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4} };
int solution(string word) {
    int answer = 0;

    for(int i = 0; i < word.size(); i++) {
        answer ++;
        
        for(int j = 0; j < mappingTable[word[i]]; j++ ) {
           for(int p = 4; i <= p; p--) {
               answer += mul[4 - p];
           }
        }
    }
    
    return answer;
}