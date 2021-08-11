#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

	string input_str;
	vector<int> alpha;
	cin >> input_str;
	for (int i = 0; i < input_str.size(); i++) {
		if (input_str[i] >= 'a' && input_str[i] <= 'z') {
			input_str[i] = input_str[i] - 'a' + 'A';
		}
	}

	for (char a = 'A'; a <= 'Z'; a++) {
		alpha.push_back(0);
	}

	for (int i = 0; i < input_str.size(); i++) {
		alpha[input_str[i] - 'A'] += 1;
	}

	int max = 0;
	char max_char = '?';
	for (int i = 0; i < alpha.size(); i++) {
		if (alpha[i] > max) {
			max = alpha[i];
			max_char = i + 'A';
		}
		else {
			if (alpha[i] == max) {
				max_char = '?';
			}
		}
	}

	cout << max_char << endl;
	
	return 0;
}