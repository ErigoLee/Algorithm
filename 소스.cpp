#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

	string input_str;
	cin >> input_str;
	vector<int> alpha;

	for (char a = 'a'; a <= 'z'; a++) {
		alpha.push_back(-1);
	}

	for (int i = 0; i < input_str.size(); i++) {
		if (alpha[input_str[i] - 'a'] == -1) {
			alpha[input_str[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < alpha.size(); i++) {
		cout << alpha[i] << " ";
	}

	
	
	return 0;
}