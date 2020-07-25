#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

struct music{
    int time;
    string title;
    string sound;
};

int calDuration(string startTime, string endTime) {
    string startHour;
    string startMinutes;
    string endHour;
    string endminutes;

    stringstream startToken(startTime);
    stringstream endToken(endTime);

    getline(startToken, startHour, ':');
    getline(startToken, startMinutes, ':');
    getline(endToken, endHour, ':');
    getline(endToken, endminutes, ':');

    int duration = (stoi(endHour) - stoi(startHour)) * 60 + (stoi(endminutes) - stoi(startMinutes));
    return duration;
}
void downSemiNote(string &sound, string origin, string translation) {
    size_t index = 0;
    while((index = sound.find(origin)) != string::npos) {
        sound.replace(sound.begin() + index, sound.begin() + origin.length() + index, translation);
        index += translation.length();
    }
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector <music> musics;
    int playingTime = 0;

    downSemiNote(m, "C#", "c");
    downSemiNote(m, "D#", "d");
    downSemiNote(m, "F#", "f");
    downSemiNote(m, "G#", "g");
    downSemiNote(m, "A#", "a");
    
    /* 입력 문자열을 token화 */
    for(string music : musicinfos) {
        stringstream token(music);
        string startTime;
        string endTime;
        string title;
        string sound;
        getline(token, startTime, ',');
        getline(token, endTime, ',');
        getline(token, title, ',');
        getline(token, sound, ',');
        downSemiNote(sound, "C#", "c");
        downSemiNote(sound, "D#", "d");
        downSemiNote(sound, "F#", "f");
        downSemiNote(sound, "G#", "g");
        downSemiNote(sound, "A#", "a");
        musics.push_back({calDuration(startTime, endTime), title, sound});
        token.clear();
    }

    /* 
    입력된 노래목록 중 노래 찾기 
    제일 긴 노래 제목 반환
    */
    for(int i = 0 ; i < musics.size(); i++) {
        int full = musics[i].time / musics[i].sound.length();
        int remain = musics[i].time % musics[i].sound.length();
        string temp = "";
        for(int j = 0 ; j < full; j++) {
            temp += musics[i].sound;
        }
        temp += musics[i].sound.substr(0, remain);
        if(temp.find(m) != string::npos) {
            if(playingTime < musics[i].time) {
                playingTime = musics[i].time;
                answer = musics[i].title;
            }
        }

    }
    return answer == "" ? "(None)" : answer;
}