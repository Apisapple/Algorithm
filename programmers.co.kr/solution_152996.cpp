#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE 100000

typedef long long ll;

vector<ll> CountWeightInfo(vector<int> weights);
ll getAnswer(vector<ll> totalCountInfo, vector<int> weights);
ll solution(vector<int> weights) {
  vector<ll> totalCountInfo = CountWeightInfo(weights);
  ll answer = getAnswer(totalCountInfo, weights);
  return answer;
}

vector<ll> CountWeightInfo(vector<int> weights) {
  vector<ll> count(1001, 0);

  for (int weight : weights) {
    count[weight]++;
  }

  return count;
}

ll getAnswer(vector<ll> totalCountInfo, vector<int> weights) {
  ll answer = 0;

  for (int weight : weights) {
    ll temp = 0;

    if (weight % 2 == 0) {
      temp = (weight / 2) * 3;
      if (temp <= 1000)
        answer += totalCountInfo[temp];
    }

    if (weight % 3 == 0) {
      temp = (weight / 3) * 4;
      if (temp <= 1000)
        answer += totalCountInfo[temp];
    }

    temp = weight * 2;
    if (temp <= 1000)
      answer += totalCountInfo[temp];
  }

  for (int i = 100; i <= 1000; i++) {
    if (2 <= totalCountInfo[i]) {
      answer += (ll)(totalCountInfo[i] * (totalCountInfo[i] - 1)) / 2;
    }
  }

  return answer;
}