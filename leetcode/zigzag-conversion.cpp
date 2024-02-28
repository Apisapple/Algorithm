class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) {
            return s;
        }

        int rows = 0;
        bool isDown = false;
        vector<string> temp(numRows, "");

        for (int i = 0; i < s.length(); i++) {
            if (rows == numRows - 1 || rows == 0) {
                isDown = !isDown;
            }

            temp[rows] += s[i];
            if (isDown)
                ++ rows;
            else
                -- rows;
        }

        string answer;
        for (auto &iter : temp) {
            answer += iter;
        }

        return answer;
    }
};