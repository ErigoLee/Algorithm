#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checking(int checkNum, int Num) {

	if (checkNum >= 1000) {
		int n_1000 = checkNum / 1000;
		int n_100 = (checkNum - n_1000 * 1000) / 100;
		int n_10 = (checkNum - n_1000 * 1000 - n_100 * 100) / 10;
		int n_1 = (checkNum - n_1000 * 1000 - n_100 * 100) % 10;

		if (checkNum + n_1000 + n_100 + n_10 + n_1 == Num)
			return true;
		else
			return false;
	}
	else if (checkNum >= 100) {
		int n_100 = checkNum / 100;
		int n_10 = (checkNum - n_100 * 100) / 10;
		int n_1 = (checkNum - n_100 * 100) % 10;
		if (checkNum + n_100 + n_10 + n_1 == Num)
			return true;
		else
			return false;
	}
	else if (checkNum >= 10) {
		int n_10 = checkNum / 10;
		int n_1 = checkNum % 10;
		if (checkNum + n_10 + n_1 == Num)
			return true;
		else
			return false;
	}
	else {
		if (checkNum + checkNum == Num)
			return true;
		else
			return false;
	}
}


int main() {

	vector<int> num;
	
	
	for (int i = 1; i < 10000; i++) {
		bool check = false;
		for (int j = 1; j <= i; j++) {
			check = checking(j, i);
			if (check)
				break;
		}
		if (!check) {
			num.push_back(i);
		}
	}

	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << endl;
	}
	
	return 0;
}