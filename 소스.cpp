#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

	int testcase;
	cin >> testcase;
	int count = 0;
	for (int i = 0; i < testcase; i++) {
		string input_string;
		bool check = false;
		cin >> input_string;

		for (int j = 2; j < input_string.size(); j++) {
			for (int k = 0; k < j - 1; k++) {
				if (input_string[k] == input_string[j]) {
					if (input_string[j - 1] != input_string[j]) {
						check = true;
						break;
					}
				}
			}
			if (check)
				break;
		}

		if (!check)
			count++;
	}

	cout << count << endl;

	return 0;
}