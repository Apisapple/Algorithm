#include <string>
#include <vector>
#include <sstream>

using namespace std;

int calTime(string times) {
    stringstream ss(times);
    string t_hour;
    string t_minute;
    string t_second;
    getline(ss, t_hour, ':');
    getline(ss, t_minute , ':');
    getline(ss, t_second, ':');
    t_second.erase(t_second.begin() + 2, t_second.begin() + 3);
    int hour = stoi(t_hour) * 3600 * 1000;
    int minute = stoi(t_minute) * 60 * 1000;
    int second = stoi(t_second);
    int result = hour + minute + second;
    return result;
}

double calProcessTime(string process) {
    string temp = process.substr(0, process.size() - 1);
    double process_time = stod(temp);
    int result = process_time * 1000;
    return result;
}

int solution(vector<string> lines) {
    int answer = 0;
    int size = lines.size();
    vector<string> times;
    vector<string> process;
    vector<int> end_time;
    vector<int> process_time;
    
    /* 기존 문자열 토큰화 */
    for(int i = 0; i < size; i++) {
        stringstream ss(lines[i]);
        string temp;
        ss >> temp;
        ss >> temp;
        times.push_back(temp);
        ss >> temp;
        process.push_back(temp);
    }
    /* 각 시간 구하기 */
    for(int i = 0; i < size; i++) {
        end_time.push_back(calTime(times[i]));
    }
    /* 처리 시간 구하기 */
    for(int i = 0; i < size; i ++) {
        process_time.push_back(calProcessTime(process[i]));
    }
    double start, next;
    for(int i = 0; i < size - 1; i ++) {
        int temp = 0;
        start = end_time[i] + 1000;
        for(int j = i + 1; j < size; j++) {
            next = end_time[j] - process_time[j] + 1;
            if(next < start) {
                temp ++;
            }
        }
        if(answer < temp)
            answer = temp;
    }
    return answer + 1;
}