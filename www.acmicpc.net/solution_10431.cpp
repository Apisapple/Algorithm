#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 20

void init();
vector<int> inputStudent();
int getAnswer(vector<int> &student);
int main() {
  int testCase = 0;

  init();

  cin >> testCase;

  for (int t = 0; t < testCase; t++) {
    int testNumber, result = 0;

    cin >> testNumber;

    vector<int> student = inputStudent();
    result = getAnswer(student);

    cout << testNumber << ' ' << result << '\n';
  }

  return 0;
}

void init() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
}

vector<int> inputStudent() {
  vector<int> student(MAX, 0);

  for (int i = 0; i < MAX; i++) {
    cin >> student[i];
  }

  return student;
}

int getAnswer(vector<int> &student) {
  int result = 0;
  for (int i = 1; i < MAX; i++) {
    for (int j = 0; j < i; j++) {
      if (student[j] > student[i]) {
        result++;
      }
    }
  }

  return result;
}