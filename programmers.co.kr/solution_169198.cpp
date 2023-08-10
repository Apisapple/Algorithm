#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 1000

int calculation_distance(int m, int n, pair<int, int> start_point, pair<int, int> ball_point) {
  int min_distance = INT16_MAX;
  if (start_point.first != ball_point.first || start_point.second <= ball_point.second)
    min_distance = min(min_distance, (int)(pow(start_point.first - ball_point.first, 2) +
                                           pow(start_point.second + ball_point.second, 2)));

  if (start_point.first >= ball_point.first || start_point.second != ball_point.second)
    min_distance = min(min_distance, (int)(pow(start_point.first - 2 * m + ball_point.first, 2) +
                                           pow(start_point.second - ball_point.second, 2)));

  if (start_point.first != ball_point.first || start_point.second >= ball_point.second)
    min_distance = min(min_distance, (int)(pow(start_point.first - ball_point.first, 2) +
                                           pow(start_point.second - 2 * n + ball_point.second, 2)));

  if (start_point.first <= ball_point.first || start_point.second != ball_point.second)
    min_distance = min(min_distance, (int)(pow(start_point.first + ball_point.first, 2) +
                                           pow(start_point.second - ball_point.second, 2)));

  return min_distance;
}

// 당구대의 가로 길이 m, 세로 길이 n
// 공이 놓인 위치 startX, startY
// 매 회마다 목표로 해야하는 공들의 위치 좌표 balls
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
  vector<int> answer;
  for (vector<int> ball : balls) {
    answer.push_back(calculation_distance(m, n, {startX, startY}, {ball[0], ball[1]}));
  }

  return answer;
}