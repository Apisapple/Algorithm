#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};

void init();
bool isContainVowel(string password);
void printNotAcceptable(string password);
void printAcceptable(string password);
int main() {
  string password;

  while (true) {
    bool flag = false;
    int vowelCount = 0, consonantCount = 0;

    cin >> password;

    if (password == "end") {
      break;
    }

    flag = isContainVowel(password);

    if (!flag) {
      printNotAcceptable(password);
    } else {
      for (int i = 0; i < password.size(); i++) {
        if (password[i] == password[i + 1] && password[i] != 'o' && password[i] != 'e') {
          flag = false;
          break;
        }

        bool isVowel = false;
        for (int j = 0; j < vowel.size(); j++) {
          if (password[i] == vowel[j]) {
            isVowel = true;
            break;
          }
        }

        if (isVowel) {
          vowelCount++;
          consonantCount = 0;
        } else {
          consonantCount++;
          vowelCount = 0;
        }

        if (consonantCount == 3 || vowelCount == 3) {
          flag = false;
          break;
        }
      }

      if (!flag) {
        printNotAcceptable(password);
      } else {
        printAcceptable(password);
      }
    }
  }

  return 0;
}

void init() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
}

bool isContainVowel(string password) {
  bool flag = false;

  for (char c : vowel) {
    size_t found = password.find(c);

    if (found != string::npos) {
      flag = true;
    }
  }

  return flag;
}

void printNotAcceptable(string password) { cout << '<' << password << '>' << " is not acceptable." << '\n'; }

void printAcceptable(string password) { cout << '<' << password << '>' << " is acceptable." << '\n'; }