#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

	int A, B;
	int new_A, new_B;
	cin >> A >> B;

	int A_100 = A / 100;
	int A_10 = (A - A_100 * 100) / 10;
	int A_1 = (A - A_100 * 100) % 10;
	new_A = A_1 * 100 + A_10 * 10 + A_100;

	int B_100 = B / 100;
	int B_10 = (B - B_100 * 100) / 10;
	int B_1 = (B - B_100 * 100) % 10;
	new_B = B_1 * 100 + B_10 * 10 + B_100;

	if (new_A >= new_B) {
		cout << new_A << endl;
	}
	else {
		cout << new_B << endl;
	}
	
	return 0;
}