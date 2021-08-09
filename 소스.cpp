#include <iostream>
#include <string>

using namespace std;




int main() {

	int N;
	cin >> N;
	bool check = false;
	
	int num = N / 5;
	for (int i = num; i > -1; i--) {
		int temp = N - (i * 5);
		int num2 = temp / 3;
		int temp2 = temp % 3;
		if (temp2 == 0)
		{
			check = true;
			cout << (i + num2) << endl;
			break;
		}

	}
	if (!check) {
		cout << -1 << endl;
	}



	return 0;
}