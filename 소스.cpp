#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int N;

int solution(vector<vector<int>> graph, vector<pair<int, char>> directions)
{
	int timer = 0;
	int direction_pointer = 0;
	int direction = 0; //πÊ«‚

	pair<int, int> head = make_pair(0,0);
	graph[0][0] = 2;//πÏ ¡∏¿Á
	
	queue<pair<int, int>> _queue;
	_queue.push(head);

	while (!_queue.empty()) {
		int head_first = _queue.back().first;
		int head_second = _queue.back().second;
		//cout << head_first << " " << head_second << endl;
		//cout << direction << endl;
		if (direction_pointer < directions.size()) {
			if (directions[direction_pointer].first == timer) {
				if (directions[direction_pointer].second == 'D') {
					direction++;
					if (direction >= 4)
						direction = 0;
				}
				else {
					direction--;
					if (direction < 0)
						direction = 3;
				}
				direction_pointer++;
			}
		}
		timer++;
		if (direction == 0) {
			int next_head_first = head_first;
			int next_head_second = head_second + 1;
			if (next_head_second < N) {
				if (graph[next_head_first][next_head_second] == 0) {
					_queue.push(make_pair(next_head_first, next_head_second));
					graph[next_head_first][next_head_second] = 2;
					int tail_first = _queue.front().first;
					int tail_second = _queue.front().second;
					graph[tail_first][tail_second] = 0;
					_queue.pop();
					
				}
				else if (graph[next_head_first][next_head_second] == 1) {
					_queue.push(make_pair(next_head_first, next_head_second));
					graph[next_head_first][next_head_second] = 2;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
		else if (direction == 1) {
			int next_head_first = head_first+1;
			int next_head_second = head_second;
			if (next_head_first < N) {
				if (graph[next_head_first][next_head_second] == 0) {
					_queue.push(make_pair(next_head_first, next_head_second));
					graph[next_head_first][next_head_second] = 2;
					int tail_first = _queue.front().first;
					int tail_second = _queue.front().second;
					graph[tail_first][tail_second] = 0;
					_queue.pop();
					
				}
				else if (graph[next_head_first][next_head_second] == 1) {
					_queue.push(make_pair(next_head_first, next_head_second));
					graph[next_head_first][next_head_second] = 2;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
		else if (direction == 2) {
			int next_head_first = head_first;
			int next_head_second = head_second - 1;
			if (next_head_second >= 0) {
				if (graph[next_head_first][next_head_second] == 0) {
					_queue.push(make_pair(next_head_first, next_head_second));
					graph[next_head_first][next_head_second] = 2;
					int tail_first = _queue.front().first;
					int tail_second = _queue.front().second;
					graph[tail_first][tail_second] = 0;
					_queue.pop();
					
				}
				else if (graph[next_head_first][next_head_second] == 1) {
					_queue.push(make_pair(next_head_first, next_head_second));
					graph[next_head_first][next_head_second] = 2;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
		else {
			int next_head_first = head_first - 1;
			int next_head_second = head_second;
			if (next_head_first >= 0) {
				if (graph[next_head_first][next_head_second] == 0) {
					_queue.push(make_pair(next_head_first, next_head_second));
					graph[next_head_first][next_head_second] = 2;
					int tail_first = _queue.front().first;
					int tail_second = _queue.front().second;
					graph[tail_first][tail_second] = 0;
					_queue.pop();
					
				}
				else if (graph[next_head_first][next_head_second] == 1) {
					_queue.push(make_pair(next_head_first, next_head_second));
					graph[next_head_first][next_head_second] = 2;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}

		

	}


	return timer;
}

int main() {

	
	cin >> N;
	int K;
	cin >> K;
	vector<vector<int>> graph;
	vector<int> temp;
	for (int i = 0; i < N; i++) {
		temp.push_back(0);
	}
	for (int i = 0; i < N; i++) {
		graph.push_back(temp);
	}

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
	}

	int direct_count;
	cin >> direct_count;
	vector<pair<int, char>> directions;
	for (int i = 0; i < direct_count; i++) {
		int a;
		char b;
		cin >> a >> b;
		pair<int, char> _direct = make_pair(a,b);
		directions.push_back(_direct);
	}

	int result = solution(graph,directions);
	cout << result << endl;
	return 0;
}