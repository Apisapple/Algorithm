#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string formatTime(int time) {
  int hour = time / 60;
  int minute = time % 60;
  string formattedTime = (hour < 10 ? "0" : "") + to_string(hour) + ":";
  formattedTime += (minute < 10 ? "0" : "") + to_string(minute);
  return formattedTime;
}

int convertToMinutes(const string &time) {
  int hour = stoi(time.substr(0, 2));
  int minute = stoi(time.substr(3, 2));
  return hour * 60 + minute;
}

string solution(int n, int t, int m, vector<string> timetable) {
  string answer = "";

  sort(timetable.begin(), timetable.end());

  vector<int> times;
  for (auto time : timetable) {
    times.push_back(convertToMinutes(time));
  }

  int index = 0, result = 0;
  int busTime = 540;
  for (int count = 1; count <= n; ++count) {
    int passenger = 0;

    while (passenger < m && index < times.size() && times[index] <= busTime) {
      ++passenger;
      ++index;
    }

    if (count == n) {
      result = (passenger < m) ? busTime : times[index - 1] - 1;
    }

    busTime += t;
  }

  return formatTime(result);
}

int main() {

  assert(solution(1, 1, 5, {"08:00", "08:01", "08:02", "08:03"}) == "09:00");
  assert(solution(2, 10, 2, {"09:10", "09:09", "08:00"}) == "09:09");
  assert(solution(2, 1, 2, {"09:00", "09:00", "09:00", "09:00"}) == "08:59");
  assert(solution(1, 1, 5, {"00:01", "00:01", "00:01", "00:01", "00:01"}) == "00:00");
  assert(solution(1, 1, 1, {"23:59"}) == "09:00");
  assert(solution(10, 60, 45,
                  {"23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59",
                   "23:59", "23:59", "23:59", "23:59", "23:59"}) == "18:00");

  return 0;
}
