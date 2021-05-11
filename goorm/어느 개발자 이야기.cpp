#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

int changeTen(int num, int index) {
	int result = 0, pivot = 1;
	while(num > 0) {
		result += (num % 10) * pivot;
		pivot = pivot * index;
		num /= 10;
	}
	return result;
}
int findMin(int num) {
	int result = 1;
	while(num > 0) {
		result = max(result, num % 10);
		num /= 10;
	}
	return result + 1;
}
bool checkNum(int num) {
	bool result = false;
	int index = 1;
	while(num >= index * index) {
		if(num == index * index)
			return true;
		index ++;
	}
	return false;
}
int main() {
	int crypt = 0, result = 1;
	cin >> crypt;
	
	for(int i = findMin(crypt); 1; i++) {
		int temp = changeTen(crypt, i);
		if(checkNum(temp)) {
			result = i;
			break;
		}
	}
	cout << result << endl;
	return 0;
}