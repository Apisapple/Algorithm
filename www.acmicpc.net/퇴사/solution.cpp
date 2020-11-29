#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	int tempDay, tempCost;
	int temp;
	cin >> n; 
    vector<pair <int, int>> cunsulting_list(n + 1);
	vector<int> cost(n + 1, 0);
	vector<int> day(n + 1, 0);
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> tempDay >> tempCost;
		cunsulting_list[i].second = tempCost;
		cunsulting_list[i].first = tempDay;
	}
	for (int i = 0; i < n; i++) {
		if (i + cunsulting_list[i].first > n)
			continue;
		if (dp[i + cunsulting_list[i].first] < dp[i] + cunsulting_list[i].second) {
			dp[i + cunsulting_list[i].first] = dp[i] + cunsulting_list[i].second;
			for (int j = i + cunsulting_list[i].first; j <= n; j++) {
				if (dp[j] < dp[i + cunsulting_list[i].first]) {
					dp[j] = dp[i + cunsulting_list[i].first];
				}
			}
		}
	}
	cout << dp[n];
	return 0;
}