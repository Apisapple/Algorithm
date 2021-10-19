#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<pair<int, int>> temp;

    for (int i = 0; i < sizes.size(); i++) {
        sizes[i][0] < sizes[i][1] ? temp.push_back(make_pair(sizes[i][1], sizes[i][0]))
                                  : temp.push_back(make_pair(sizes[i][0], sizes[i][1]));
    }

    int width = 0, height = 0;
    for(int i = 0; i < temp.size(); i++) {
        width = (width < temp[i].first) ? temp[i].first : width;
        height = (height < temp[i].second) ? temp[i].second : height;
    }

    return height * width;
}