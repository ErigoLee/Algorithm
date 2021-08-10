#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n[10001];
int n2[10001];
int n3[10001];
int main() {
	string A, B;
	cin >> A >> B;

	for (int i = 0; i < A.size(); i++) {
		n[10001 - (A.size() - i)] = A[i] - '0';
	}

	for (int i = 0; i < B.size(); i++) {
		n2[10001 - (B.size() - i)] = B[i] - '0';
	}

	int temp = 0;
	for (int i = 10000; i > -1; i--) {
		int sum = n[i] + n2[i] + temp;
		temp = sum / 10;
		sum = sum % 10;
		n3[i] = sum;
	}

	string answer = "";
	bool check = false;
	for (int i = 0; i < 10001; i++) {
		if (check) {
			answer += to_string(n3[i]);
		}
		else {
			if (n3[i] != 0) {
				check = true;
				answer += to_string(n3[i]);
			}
		}

	}
	cout << answer << endl;
	return 0;
}