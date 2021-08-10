#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;
	int temp = V;
	temp = temp - A;
	int count = temp / (A - B);
	if (count * (A - B) + A >= V) {
		cout << count + 1 << endl;
	}
	else {
		cout << count + 2 << endl;
	}

	/*
	int count = 0;
	int sum = 0;
	while (true) {
		sum += A;
		count++;
		if (sum >= V) {
			break;
		}
		sum -= B;
	}
	cout << count << endl;
	*/
	

	return 0;
}