#include <iostream>
#include <string>
#include <vector>

using namespace std;




int main() {

	int num;
	int count = 0;
	cin >> num;

	int check, check2;
	bool pass = false;

	int num2 = 0;
	while (true) {
		num2++;
		for (int i = 0; i <num2; i++) {
			count++;
			if (count == num) {

				if (num2 % 2 == 1) {
					check2 = i + 1;
					check = num2 - (i);
				}
				else {
					check = i + 1;
					check2 = num2 - (i);
				}
				
				pass = true;
				break;
			}
		}
		if (pass)
			break;
		
	}
	
	string answer = to_string(check) + "/" + to_string(check2);

	cout << answer << endl;

	return 0;
}