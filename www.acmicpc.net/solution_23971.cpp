#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class solution {
private:
  int h = 0, w = 0, n = 0, m = 0;

public:
  solution();
  ~solution();

  int get_answer();
  void input_data();
};

solution::solution() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
}

solution::~solution() {}

int solution::get_answer() {
  int col, row;

  input_data();

  col = (h % (n + 1)) != 0 ? (h / (n + 1)) + 1 : (h / (n + 1));
  row = (w % (m + 1)) != 0 ? (w / (m + 1)) + 1 : (w / (m + 1));

  return col * row;
}

void solution::input_data() { cin >> h >> w >> n >> m; }

int main(int argc, char const *argv[]) {

  auto sol = new solution();
  auto answer = sol->get_answer();

  printf("%d\n", answer);

  return 0;
}
