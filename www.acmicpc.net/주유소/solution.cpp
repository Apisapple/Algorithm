#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void init() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main() {
    init();

    int city_count = 0;
    cin >> city_count;

    vector<int> oil_price_list(city_count, 0);
    vector<int> use_oil_info(city_count - 1, 0);

    for (int i = 0; i < city_count - 1; i++) {
        cin >> use_oil_info[i];
    }

    for (int i = 0; i < city_count; i++) {
        cin >> oil_price_list[i];
    }

    long long current_price = oil_price_list[0];
    long long total_price = current_price * use_oil_info[0];

    for (int i = 1; i < city_count; i++) {
        if (current_price < oil_price_list[i]) {
            total_price += current_price * use_oil_info[i];
        } else {
            current_price = oil_price_list[i];
            total_price += current_price * use_oil_info[i];
        }
    }

    cout << total_price << '\n';
    return 0;
}