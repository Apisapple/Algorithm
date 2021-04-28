#include <queue>
#include <iostream>
using namespace std;

long N, B, C;
long A[1000000] = { 0, };

long ans = 0;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		int rest = A[i] - B;
		if (rest >= 0) {
			if (rest % C > 0) {
				ans += rest / C + 2;
			}
			else if (rest % C == 0) {
				ans += rest / C + 1;
			}
		}
		else if (rest < 0) {
			ans += 1;
		}
	}

	cout << ans << endl;
}