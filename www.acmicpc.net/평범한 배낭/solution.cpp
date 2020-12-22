#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int pack_count = 0, max_weight = 0;
    cin >> pack_count >> max_weight;

    vector<pair<int, int>> value_list;
    vector<int> DP(100001, 0);
    for(int i = 0; i < pack_count; i++) {
        int weight, value;
        cin >> weight >> value;
        value_list.push_back(make_pair(weight, value));
    }

    for(int i = 0; i < pack_count; i++) {
        for(int j = max_weight; j >= 1; j--) {
            if(value_list[i].first <= j) {
                DP[j] = max(DP[j], DP[j - value_list[i].first] + value_list[i].second);
            }
        }
    }
    cout << DP[max_weight] << endl;
    return 0;
}