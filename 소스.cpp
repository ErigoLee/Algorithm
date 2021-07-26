#include <iostream>
#include <string>

using namespace std;

int main() {

	string sentence;
	int count = 1;
	getline(cin, sentence);
	if (sentence.length() == 1) {
		if (sentence[0] == ' ') {
			count = 0;
		}
	}

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i]==' ') {
			if (i > 0 && i<sentence.length()-1) {
				count++;
			}
		}
	}
	cout << count << endl;

	return 0;
}