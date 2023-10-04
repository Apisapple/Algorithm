#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<int, int> getNumberOfIndividuals(vector<int> tangerine);
vector<int> getSortedCountInfo(map<int, int> countInfo);
int getAnswer(int k, vector<int> tangerinInfo);
int solution(int k, vector<int> tangerine) {
  map<int, int> countInfo = getNumberOfIndividuals(tangerine);
  vector<int> tangerineInfo = getSortedCountInfo(countInfo);
  return getAnswer(k, tangerineInfo);
}

map<int, int> getNumberOfIndividuals(vector<int> tangerine) {
  map<int, int> result;
  for (int tanger : tangerine) {
    result[tanger]++;
  }

  return result;
}

vector<int> getSortedCountInfo(map<int, int> countInfo) {
  vector<int> result;

  for (auto info : countInfo) {
    result.push_back(info.second);
  }

  sort(result.begin(), result.end(), greater<int>());

  return result;
}

int getAnswer(int k, vector<int> tangerineInfo) {

  int count = 0, answer = 0;

  for (int info : tangerineInfo) {
    if (k <= count) {
      break;
    }

    answer++;
    count += info;
  }

  return answer;
}