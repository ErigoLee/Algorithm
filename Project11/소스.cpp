#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	while (N > 1) {
		for (int i = 2; i <= 10000000; i++) {
			if (N % i == 0) {
				cout << i << endl;
				N = N / i;
				break;
			}
		}
	}
	return 0;
}