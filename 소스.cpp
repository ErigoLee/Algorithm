#include <iostream>
#include <string>
#include <vector>

using namespace std;

int DaieolNum(char daieolChar) {

	if (daieolChar >= 'A' && daieolChar <= 'C')
		return 3;
	else if (daieolChar >= 'D' && daieolChar <= 'F')
		return 4;
	else if (daieolChar >= 'G' && daieolChar <= 'I')
		return 5;
	else if (daieolChar >= 'J' && daieolChar <= 'L')
		return 6;
	else if (daieolChar >= 'M' && daieolChar <= 'O')
		return 7;
	else if (daieolChar >= 'P' && daieolChar <= 'S')
		return 8;
	else if (daieolChar >= 'T' && daieolChar <= 'V')
		return 9;
	else
		return 10;

}

int main() {

	string input_str;
	cin >> input_str;
	int sum = 0;
	for (int i = 0; i < input_str.size(); i++) {
		sum += DaieolNum(input_str[i]);
	}
	
	cout << sum << endl;
	
	return 0;
}