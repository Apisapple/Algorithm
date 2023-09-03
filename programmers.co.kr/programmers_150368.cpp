#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int maxEomoticonPlus = 0;
int maxSales = 0;

void searchAnswer(vector<int> discountRates, vector<vector<int>> &users, vector<int> &emoticons);
void calcAnswer(vector<int> discountRates, vector<vector<int>> &users, vector<int> &emoticons);
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
  vector<int> discountRates;
  vector<int> answer;

  searchAnswer(discountRates, users, emoticons);

  answer.push_back(maxEomoticonPlus);
  answer.push_back(maxSales);
  return answer;
}

void searchAnswer(vector<int> discountRates, vector<vector<int>> &users, vector<int> &emoticons) {
  if (discountRates.size() == emoticons.size()) {
    calcAnswer(discountRates, users, emoticons);

    return;
  }

  for (int i = 10; i <= 40; i += 10) {
    discountRates.push_back(i);
    searchAnswer(discountRates, users, emoticons);
    discountRates.pop_back();
  }
}

void calcAnswer(vector<int> discountRates, vector<vector<int>> &users, vector<int> &emoticons) {
  int emoticonsPlus = 0, sales = 0;

  for (auto user : users) {
    int temp = 0;

    for (int i = 0; i < discountRates.size(); i++) {
      if (user[0] > discountRates[i]) {
        continue;
      }

      temp += (emoticons[i] / 100) * (100 - discountRates[i]);
    }

    if (temp >= user[1]) {
      emoticonsPlus++;
    } else {
      sales += temp;
    }
  }

  if (maxEomoticonPlus > emoticonsPlus) {
    return;
  }

  if (maxEomoticonPlus == emoticonsPlus && maxSales >= sales) {
    return;
  }

  maxEomoticonPlus = emoticonsPlus;
  maxSales = sales;
}