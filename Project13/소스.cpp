#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int a;
	vector<int> result;
	while (true) {
		cin >> a;
		if (a == 0)
			break;
		int max = 2 * a;
		int max_count = 0;
		bool* numbers = new bool[max + 1];
		numbers[0] = false; numbers[1] = false;
		for (int i = 2; i <= max; i++)
			numbers[i] = true;
		for (int i = 2; i <= max; i++) {
			if (numbers[i] == false)
				continue;
			for (int j = i+i; j <=max; j=j+i) {
				if (numbers[j] == true)
					numbers[j] = false;
			}
			
		}
		for (int i = a + 1; i <= max; i++) {
			if (numbers[i] == true)
				max_count++;
		}

		result.push_back(max_count);
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	return 0;
}