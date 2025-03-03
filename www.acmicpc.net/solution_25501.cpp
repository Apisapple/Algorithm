#include <iostream>

using namespace std;

int count = 0;

int recursion(const string &s, int l, int r) {
  count++;
  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1);
}

int isPalindrome(const string &s) { return recursion(s, 0, s.size() - 1); }

void init() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
}

int main() {

  init();

  int n = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string temp = "";
    cin >> temp;

    cout << isPalindrome(temp) << ' ' << count << '\n';
    count = 0;
  }

  return 0;
}