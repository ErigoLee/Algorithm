#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
	}
	else {
		int count = 1;
		int prev = 1;
		while (true) {
			int num = 6 * count  + prev;
			if (num >= N) {
				break;
			}
			count++;
			prev = num;
			
		}
		cout << count + 1 << endl;
	}
	
	return 0;
}