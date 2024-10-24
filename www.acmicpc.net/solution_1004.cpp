#include <iostream>
#include <math.h>

using namespace std;

void init() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
}

bool isInPlanet(int &planetX, int &planetY, int &radius, int &x, int &y) {
  return pow(planetX - x, 2) + pow(planetY - y, 2) <= radius * radius;
}

int solveProblem() {
  int startX, startY, destX, destY;
  cin >> startX >> startY >> destX >> destY;

  int count = 0;
  cin >> count;

  int enterCount = 0, leaveCount = 0;
  for (size_t i = 0; i < count; i++) {
    int x, y, radius;
    cin >> x >> y >> radius;

    if(isInPlanet(x, y, radius, startX, startY)) {
      if(!isInPlanet(x, y, radius, destX, destY)) {
        leaveCount ++;
      }
    }

    if(isInPlanet(x, y, radius, destX, destY)) {
      if(!isInPlanet(x, y, radius, startX, startY)) {
        enterCount ++;
      }
    }
  }

  return enterCount + leaveCount;
}

int main() {

  init();

  int T = 0;
  cin >> T;
  while (T--) {
    cout << solveProblem() << '\n';
  }

  return 0;
}
