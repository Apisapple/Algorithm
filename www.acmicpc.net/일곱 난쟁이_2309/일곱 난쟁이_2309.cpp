/* URL : https://www.acmicpc.net/problem/2309 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> people;
    for(int i = 0; i < 9; i ++){
        int input = 0;
        cin >> input;
        people.push_back(input);
    }
    int total = 0;
    int except = 0;
    for(int i = 0; i < people.size(); i ++) {
        total += people[i];
    }
    for(int i = 0; i < people.size() - 1; i ++) {
        for(int j = i + 1; j < people.size(); j++) {
            except = people[i] + people[j];
            if(total - except == 100) {
                people[i] = 0;
                people[j] = 0;
                sort(people.begin(), people.end());
                for(int i = 2; i < people.size(); i++) {
                    cout << people[i] << endl;
                }
                return 0;
            }
        }
    }
}