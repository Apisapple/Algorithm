#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define MAX_LEN 100000

set<string> setGemsCategory(vector<string> gems);
vector<int> searchAnswer(vector<string> gems, set<string> category);

vector<int> solution(vector<string> gems) {
  set<string> gemsCategory = setGemsCategory(gems);
  vector<int> answer = searchAnswer(gems, gemsCategory);
  return answer;
}

set<string> setGemsCategory(vector<string> gems) {
  set<string> gemsCategory;

  for (string gem : gems) {
    gemsCategory.insert(gem);
  }

  return gemsCategory;
}

vector<int> searchAnswer(vector<string> gems, set<string> category) {
  unordered_map<string, int> totalGemsCount;
  vector<int> answer(2, 0);
  int startIndex = 0, endIndex = 0;
  int minLength = 0;

  for (string gem : gems) {
    totalGemsCount[gem]++;
    if (totalGemsCount.size() == category.size()) {
      break;
    }

    endIndex++;
  }

  answer[0] = startIndex + 1;
  answer[1] = endIndex + 1;
  minLength = endIndex - startIndex;

  while (endIndex < gems.size()) {
    // start index 당겨오기
    string key = gems[startIndex];
    totalGemsCount[key]--;
    startIndex++;

    if (totalGemsCount[key] == 0) {
      endIndex++;
      while (endIndex < gems.size()) {
        totalGemsCount[gems[endIndex]]++;
        if (key == gems[endIndex])
          break;

        endIndex++;
      }
    }

    if (endIndex - startIndex < minLength) {
      answer[0] = startIndex + 1;
      answer[1] = endIndex + 1;
      minLength = endIndex - startIndex;
    }
  }

  return answer;
}