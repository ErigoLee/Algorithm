#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checking(int num) {

	if (num == 1000)
		return false;
	else {
		int n_100 = num / 100;
		int n_10 = (num - n_100 * 100) / 10;
		int n_1 = (num - n_100 * 100) % 10;
		if (n_10 * 2 == n_100 + n_1)
			return true;
		else
			return false;
	}
}


int main() {

	int N;
	int count = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i < 100) {
			count++;
		}
		else {
			bool check = checking(i);
			if (check)
				count++;
		}
	}

	cout << count << endl;
	
	
	return 0;
}