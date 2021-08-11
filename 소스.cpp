#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	long long A, B, C;
	cin >> A >> B >> C;
	
	if (B >= C) {
		cout << -1 << endl;
	}
	else {
		long long N = A / (C - B);
		cout << N + 1 << endl;
	}

	/*
	if (B >= C) {
		cout << -1 << endl;
	}
	else {
		long long N = 1;
		while (true) {
			long long gain = C * N;
			long long loss = A + (B * N);
			if (gain > loss) {
				break;
			}
			N++;
		}
		cout << N << endl;
	}
	*/
	
	return 0;
}