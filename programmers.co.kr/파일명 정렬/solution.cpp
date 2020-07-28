#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 정렬하는데 고려해야 할 것은 head와 number 뿐
struct fileName{
    string head;
    int number;
    int index;

};

bool compare(fileName a, fileName b) {
    
    std::transform(a.head.begin(), a.head.end(), a.head.begin(), ::tolower);
    std::transform(b.head.begin(), b.head.end(), b.head.begin(), ::tolower);

    if(a.head == b.head) {
       return a.number < b.number;
    }

    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<fileName> fileinfo;
    fileName temp;
    for(int i = 0; i < files.size(); i ++) {
        for(int j = 0; j < files[i].size(); j ++) {
            if(files[i][j] >= '0' && files[i][j] <= '9') {
                /* Head 부분 구하기 */
                temp.head = files[i].substr(0, j);
                /* number 부분 구하기 */
                vector<int> value;
                for(int k = j; k < files[i].size(); k ++) {
                    if(files[i][k] >= '0' && files[i][k] <= '9')
                        value.push_back(files[i][k] - '0');
                    else 
                        break;
                }
                int number = 0;
                int pos = 1;       
                for(int k = value.size() - 1; k > -1; k--) {
                    number += value[k] * pos;
                    pos *= 10;
                }
                temp.number = number;
                temp.index = i;
                fileinfo.push_back(temp);
                break;
            }
        }
    }

    sort(fileinfo.begin(),fileinfo.end(), compare);

    for(fileName information : fileinfo) {
        answer.push_back(files[information.index]);
    }

    return answer;
}