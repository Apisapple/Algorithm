#include <algorithm>
#include <vector>

#define MAX_SIZE 100000

using namespace std;

int openFirstSticker(vector<int> sticker);
int openSecondSticker(vector<int> sticker);
int solution(vector<int> sticker) {

  if(sticker.size() == 1) {
    return sticker[0];
  }

  int firstAnswer = openFirstSticker(sticker);
  int secondAnswer = openSecondSticker(sticker);

  return max(firstAnswer, secondAnswer); 
}

int openFirstSticker(vector<int> sticker) {
  int sticker_size = sticker.size();
  vector<int> dp(MAX_SIZE + 1, 0);

  dp[0] = sticker[0];
  dp[1] = sticker[0];

  for (int i = 2; i < sticker.size() - 1; i++) {
    dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
  }

  return dp[sticker.size() - 2];
}

int openSecondSticker(vector<int> sticker) {
  int sticker_size = sticker.size();
  vector<int> dp(MAX_SIZE + 1, 0);

  dp[0] = 0;
  dp[1] = sticker[1];

  for (int i = 2; i < sticker.size(); i++) {
    dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
  }

  return dp[sticker.size() - 1];
}