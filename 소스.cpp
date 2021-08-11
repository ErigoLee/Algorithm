#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

	string input_str;
	cin >> input_str;
	
	int count = 0;
	for (int i = 0; i < input_str.size(); i++) {
		count++;
		if (input_str[i] == 'c') {
			if (i + 1 < input_str.size()) {
				if (input_str[i + 1] == '=')
					i = i + 1;
				if (input_str[i + 1] == '-')
					i = i + 1;
			}
		}

		if (input_str[i] == 'd') {
			if (i + 1 < input_str.size()) {
				if (input_str[i + 1] == 'z') {
					if (i + 2 < input_str.size()) {
						if (input_str[i + 2] == '=')
							i = i + 2;
					}
				}
				if (input_str[i + 1] == '-')
					i = i + 1;
			}
		}

		if (input_str[i] == 'l') {
			if (i + 1 < input_str.size()) {
				if (input_str[i + 1] == 'j')
					i = i + 1;
			}
		}

		if (input_str[i] == 'n'){
			if (i + 1 < input_str.size()) {
				if (input_str[i + 1] == 'j')
					i = i + 1;
			}
		}

		if (input_str[i] == 's') {
			if (i + 1 < input_str.size()) {
				if (input_str[i + 1] == '=')
					i = i + 1;
			}
		}
		
		if (input_str[i] == 'z') {
			if (i + 1 < input_str.size()) {
				if (input_str[i + 1] == '=')
					i = i + 1;
			}
		}
		
	}

	cout << count << endl;

	return 0;
}