#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// info 파싱
vector<int> parse_info(string info) {
    // language cpp : 0, java : 1, python : 2
    // position back : 0, front : 1 
    // exp junior : 0, senior : 1
    // soulfood pizza : 0, chicken : 1
    vector<int> ret;
    string temp;
    int n;
    for(int i = 0; i < info.length(); i++) {
        if(info[i] == ' ') {
            if(temp == "cpp" || temp == "backend" || temp == "junior" || temp=="chicken")
                n = 0;
            else if(temp == "python")
                n = 2;
            else 
                n = 1;

            ret.push_back(n);
            temp = "";
        } else {
            temp.push_back(info[i]);
        }
    }
    ret.push_back(stoi(temp));
    return ret;
}

// query 파싱
vector<string> parse_query(string query) {
    vector<string> ret;
    string temp = "";
    for(char c : query) {
        if(c == ' ') {
            ret.push_back(temp);
            temp = "";
        } else {
            temp.push_back(c);
        }
    }
    ret.push_back(temp);
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> database[3][2][2][2];
    vector<int> answer;

    // 유저의 정보 파싱 후 저장
    for(string user : info) {
        vector<int> temp = parse_info(user);
        database[temp[0]][temp[1]][temp[2]][temp[3]].push_back(temp[4]);
    }
    // 유저 정보 정렬
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                for(int l = 0; l < 2; l++)
                    sort(database[i][j][k][l].begin(), database[i][j][k][l].end());

    // query문 실행
    for(string value : query) {
        vector <string> s = parse_query(value);
        int sl, el, sp, ep, se, ee, sf, ef;
        // 언어 정보 파싱
        if(s[0] == "cpp") {
            sl = 0;
            el = 0;
        } else if (s[0] == "java") {
            sl = 1;
            el = 1;
        } else if (s[0] == "python") {
            sl = 2;
            el = 2;
        } else if (s[0] == "-") {
            sl = 0;
            el = 2;
        }

        // 직무 파싱
        if(s[2] == "backend") {
            sp = 0;
            ep = 0;
        }else if(s[2] == "frontend") {
            sp = 1;
            ep = 1;
        }else if(s[2] == "-") {
            sp = 0;
            ep = 1;
        }

        // 경력 파싱
        if(s[4] == "junior") {
            se = 0;
            ee = 0;
        }else if(s[4] == "senior") {
            se = 1;
            ee = 1;
        }else if(s[4] == "-") {
            se = 0;
            ee = 1;
        }

        if(s[6] == "chicken") {
            sf = 0;
            ef = 0;
        }else if(s[6] == "pizza") {
            sf = 1;
            ef = 1;
        }else if(s[6] == "-") {
            sf = 0;
            ef = 1;
        }

        int score = stoi(s[7]);

        int ans = 0;
        for(int i = sl; i <= el; i++) {
            for(int j = sp; j <= ep; j++) {
                for(int p = se; p <= ee; p++) {
                    for(int q = sf; q <= ef; q++) {
                        int n = database[i][j][p][q].size();
                        if(n == 0)
                            continue;

                        auto iter = lower_bound(database[i][j][p][q].begin(), database[i][j][p][q].end(), score);

                        if(iter == database[i][j][p][q].end())
                            continue;
                        ans += n - (iter - database[i][j][p][q].begin());
                    }
                }
            }
        }
        answer.push_back(ans);
    }
    
    
    return answer;
}