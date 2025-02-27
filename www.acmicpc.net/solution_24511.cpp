#include <deque>
#include <iostream>
#include <vector>

void init() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
}

void solution(std::vector<int> &dataStructTypes, std::vector<int> &numberList, std::vector<int> &queryList) {

  std::deque<int> dq;
  for (size_t i = 0; i < numberList.size(); i++) {
    if (dataStructTypes[i] != 1) {
      dq.push_back(numberList[i]);
    }
  }

  for (size_t i = 0; i < queryList.size(); i++) {
    dq.push_front(queryList[i]);
    int value = dq.back();
    std::cout << value << " ";
    dq.pop_back();
  }
}

int main() {

  int N = 0;
  std::cin >> N;

  std::vector<int> dataStructTypes(N);
  for (size_t i = 0; i < N; i++) {
    std::cin >> dataStructTypes[i];
  }

  std::vector<int> numberList(N);
  for (size_t i = 0; i < N; i++) {
    std::cin >> numberList[i];
  }

  int M = 0;
  std::cin >> M;

  std::vector<int> queryList(M);
  for (size_t i = 0; i < M; i++) {
    std::cin >> queryList[i];
  }

  solution(dataStructTypes, numberList, queryList);
  return 0;
}
