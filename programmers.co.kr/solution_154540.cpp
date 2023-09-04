#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void makeAnswer(vector<string> &maps, vector<int> &answer);
vector<vector<bool>> makeVisitedMap(vector<string> &maps);
void searchMaxNumberOfDays(vector<string> &maps, vector<vector<bool>> visited, vector<int> &answer, int total);
bool isEndOfLand(vector<vector<bool>> visited);
vector<int> solution(vector<string> maps) {
  vector<int> answer;

  makeAnswer(maps, answer);

  return answer;
}

void makeAnswer(vector<string> &maps, vector<int> &answer) {
  vector<vector<bool>> visited = makeVisitedMap(maps);
  
  searchMaxNumberOfDays(maps, visited, answer, 0);
  
  sort(answer.begin(), answer.end());
  
  if(answer.size() == 0)
    answer.push_back(-1);
}

vector<vector<bool>> makeVisitedMap(vector<string> &maps) {
  int width = maps.at(0).size();
  int height = maps.size();

  vector<vector<bool>> result(height, vector<bool>(width, false));

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (maps[i][j] != 'X') {
        result[i][j] = true;
      }
    }
  }

  return result;
}

// TODO : searchMaxNumberOfDays 함수 구현 필요