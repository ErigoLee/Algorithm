#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int expenseCal(vector<pair<int,int>> days, int N) {

	int _max = 0;
	//현재 날짜 위치, 비용
	queue <pair<int, int>> _queue;
	
	for (int i = 0; i < N; i++) {

		pair<int, int> _day = days[i];
		int time = _day.first;
		int expense = _day.second;
		if (i + time <= N) {
			pair<int, int> _temp = make_pair(i+time,expense);
			_queue.push(_temp);
		}
	}


	while (!_queue.empty()) {

		int palace = _queue.front().first;
		int totalExpense = _queue.front().second;

		_queue.pop();
		if (totalExpense > _max)
		{
			_max = totalExpense;
		}

		for (int i = palace; i < N; i++) {
			pair<int, int> _day = days[i];
			int time = _day.first;
			int expense = _day.second;
			if (i + time <= N) {
				int nextPalace = i + time;
				int nextExpense = expense + totalExpense;
				pair<int, int> _next = make_pair(nextPalace,nextExpense);
				_queue.push(_next);
			}
		}
	}

	return _max;

}




int main() {

	int N;
	cin >> N;
	vector<pair<int, int>> days;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> _day = make_pair(a, b);
		days.push_back(_day);
	}

	int result = expenseCal(days,N);

	cout << result << endl;
	
	return 0;
}