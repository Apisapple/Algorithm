#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 1000

class BoundaryInformation {
public:
  int boundaryLeft;
  int boundaryRight;
  int boundaryDown;
  int boundaryUp;
  int x;
  int y;

  BoundaryInformation(int m, int n, pair<int, int> coordinates) {
    this->boundaryLeft = coordinates.first;
    this->boundaryRight = m - coordinates.first;
    this->boundaryUp = n - coordinates.second;
    this->boundaryDown = coordinates.second;
    this->x = coordinates.first;
    this->y = coordinates.second;
  }
};

int calculation_distance(BoundaryInformation startPoint, BoundaryInformation destPoint) {
  int distance = INT16_MAX;
  int left = (int)pow((startPoint.boundaryLeft + destPoint.boundaryLeft), 2) + (int)pow(startPoint.y - destPoint.y, 2);
  int right =
      (int)pow((startPoint.boundaryRight + destPoint.boundaryRight), 2) + (int)pow(startPoint.y - destPoint.y, 2);
  int down = (int)pow((startPoint.boundaryDown + destPoint.boundaryDown), 2) + (int)pow(startPoint.x - destPoint.x, 2);
  int up = (int)pow((startPoint.boundaryUp + destPoint.boundaryUp), 2) + (int)pow(startPoint.x - destPoint.x, 2);

  if (startPoint.x == destPoint.x) {
    if (destPoint.y > startPoint.y)
      distance = min(min(left, right), down);
    else
      distance = min(min(left, right), up);
  } else if (startPoint.y == destPoint.y) {
    if (destPoint.x > startPoint.x)
      distance = min(min(up, down), left);
    else
      distance = min(min(up, down), right);
  } else {
    distance = min(min(left, right), min(up, down));
  }

  return distance;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
  vector<int> answer;
  for (vector<int> ball : balls) {
    BoundaryInformation startPoint = BoundaryInformation(m, n, {startX, startY});
    BoundaryInformation endPoint = BoundaryInformation(m, n, {ball[0], ball[1]});
    answer.push_back(calculation_distance(startPoint, endPoint));
  }

  return answer;
}