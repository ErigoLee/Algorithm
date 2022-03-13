#include <iostream>

using namespace std;

int main() {
	int hour; int min; //입력시간
	int interval; //요리하는데 필요한 시간
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