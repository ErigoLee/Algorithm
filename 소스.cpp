#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> resetVisited(vector<vector<bool>> visited,int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	return visited;
}




int main() {

	int N, L, R;
	cin >> N >> L >> R;
	int count = 0;
	vector<vector<int>> _graph;

	vector<vector<bool>> visited;

	for (int i = 0; i < N; i++) {
		vector<int> _temp;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			_temp.push_back(a);
		}
		_graph.push_back(_temp);
		_temp.clear();
	}

	//visited
	vector<bool> _temp2;
	for (int i = 0; i < N; i++) {
		_temp2.push_back(false);
	}

	for (int i = 0; i < N; i++) {
		visited.push_back(_temp2);
	}

	bool tryagain = false;

	for (int k = 0; k < N; k++) {
		for (int l = 0; l < N; l++) {

			if (visited[k][l] == true)
				continue;
			vector<pair<int, int>> movesIndex;
			pair<int, int> _pair = make_pair(k, l);
			movesIndex.push_back(_pair);
			visited[k][l] = true;
			queue<pair<int, int>> _queue;
			_queue.push(_pair);
			while (!_queue.empty()) {
				int current_x = _queue.front().first;
				int current_y = _queue.front().second;
				_queue.pop();
				
				if (current_x - 1 >= 0) {
					int next_x = current_x - 1;
					int next_y = current_y;
					int diff = abs(_graph[current_x][current_y] - _graph[next_x][next_y]);
					if (diff >= L && diff <= R) {
						int size = movesIndex.size();
						if (visited[next_x][next_y] == false) {
							pair<int, int> _next = make_pair(next_x, next_y);
							movesIndex.push_back(_next);
							_queue.push(_next);
							visited[next_x][next_y] = true;
						}
					}
				}

				if (current_x + 1 < N) {
					int next_x = current_x + 1;
					int next_y = current_y;
					int diff = abs(_graph[current_x][current_y] - _graph[next_x][next_y]);
					if (diff >= L && diff <= R) {
						int size = movesIndex.size();
						if (visited[next_x][next_y] == false) {
							pair<int, int> _next = make_pair(next_x, next_y);
							movesIndex.push_back(_next);
							_queue.push(_next);
							visited[next_x][next_y] = true;
						}
					}
				}

				if (current_y - 1 >= 0) {
					int next_x = current_x;
					int next_y = current_y - 1;
					int diff = abs(_graph[current_x][current_y] - _graph[next_x][next_y]);
					if (diff >= L && diff <= R) {
						int size = movesIndex.size();
						if (visited[next_x][next_y] == false) {
							pair<int, int> _next = make_pair(next_x, next_y);
							movesIndex.push_back(_next);
							_queue.push(_next);
							visited[next_x][next_y] = true;
						}
					}
				}

				if (current_y + 1 < N) {
					int next_x = current_x;
					int next_y = current_y + 1;
					int diff = abs(_graph[current_x][current_y] - _graph[next_x][next_y]);
					if (diff >= L && diff <= R) {
						int size = movesIndex.size();

						if (visited[next_x][next_y] == false) {
							pair<int, int> _next = make_pair(next_x, next_y);
							movesIndex.push_back(_next);
							_queue.push(_next);
							visited[next_x][next_y] = true;
						}
					}
				}
			}

			if (movesIndex.size() > 1) {
				tryagain = true;
				int size = movesIndex.size();
				int total = 0;
				for (int j = 0; j < size; j++) {
					int x = movesIndex[j].first;
					int y = movesIndex[j].second;
					total += _graph[x][y];
				}
				int value = total / size;
				for (int j = 0; j < size; j++) {
					int x = movesIndex[j].first;
					int y = movesIndex[j].second;
					_graph[x][y] = value;
				}

			}
			else {
				//아무것도 탐색하지 않는 경우
				visited[k][l] = false;
			}
			
			movesIndex.clear();
		}

		if (k == N - 1) {
			if (tryagain) {
				count++;
				tryagain = false;
				k = -1;
				visited = resetVisited(visited,N);
			}
		}
		
	}
	cout << count << endl;
	return 0;
}