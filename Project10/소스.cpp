#include <iostream>

using namespace std;

int main() {
	int dice, dice2, dice3; //주사위값
	int result;//결과값
	cin >> dice >> dice2 >> dice3;
	if (dice == dice2 && dice2 == dice3) {
		result = dice * 1000 + 10000;
	}
	else if (dice == dice2) {
		result = dice * 100 + 1000;
	}
	else if (dice2 == dice3) {
		result = dice2 * 100 + 1000;
	}
	else if (dice == dice3) {
		result = dice * 100 + 1000;
	}
	else {
		result = dice > dice2 ? (dice > dice3 ? dice : dice3) : (dice2 > dice3 ? dice2 : dice3);
		result = result * 100;
	}
	cout << result << endl;
}