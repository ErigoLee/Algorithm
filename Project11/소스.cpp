#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int start, end;
	//입출력 시간 단축시키기
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> start >> end;
	bool* numbers = new bool[end + 1];
	numbers[0] = false;
	numbers[1] = false;
	for (int i = 2; i <= end; i++)
		numbers[i] = true;
	//에라토스테네스의 체
	for (int i = 2; i <= sqrt(end); i++) {
		if (numbers[i] == false) {
			continue;
		}
		else {
			for (int j = i * i; j <= end; j = j + i) {
				if (numbers[j] == true)
					numbers[j] = false;
			}
		}
	}
	for (int i = start; i <= end; i++) {
		if (numbers[i] == true)
			cout << i << "\n";
	}
	
}