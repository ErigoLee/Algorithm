#include <iostream>

using namespace std;

int main() {
	int hour; int min; //�Է½ð�
	int interval; //�丮�ϴµ� �ʿ��� �ð�
	cin >> hour >> min;
	cin >> interval;
	min = min + interval;
	if (min >= 60) {
		int temp_hour = min / 60;
		int temp_min = min % 60;
		hour += temp_hour;
		min = temp_min;
	}
	if (hour >= 24) {
		hour = hour % 24;
	}
	cout << hour << " " << min << endl;
}