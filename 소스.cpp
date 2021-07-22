#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int breath_first_search(vector<vector<int>>graph,vector<pair<int,int>>index,int width,int height,int empty_count)
{
	queue<pair<int, int>> queue;
	vector<vector<bool>> visited(height);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			visited[i].push_back(false);
		}
	}
	vector<pair<int, int>> visited_order;
	int day = 0;

	for (int i = 0; i < index.size(); i++) {
		pair<int, int> pair = make_pair(index[i].first,index[i].second);
		visited[index[i].first][index[i].second] = true;
		queue.push(pair);
	}
	
	while (!queue.empty())
	{
		int size = queue.size();
		vector<pair<int, int>> next_index;
		for (int i = 0; i < size; i++) {
			int index_1 = queue.front().first;
			int index_2 = queue.front().second;
			queue.pop();
			visited_order.push_back(make_pair(index_1,index_2));
			//위
			if (index_1 - 1 >= 0) {
				int next_index_1 = index_1 - 1;
				int next_index_2 = index_2;
				if (!visited[next_index_1][next_index_2] && graph[next_index_1][next_index_2] == 0) {
					graph[next_index_1][next_index_2] = 1;
					visited[next_index_1][next_index_2] = true;
					next_index.push_back(make_pair(next_index_1,next_index_2));
				}
			}
			//아래
			if (index_1 + 1 < height) {
				int next_index_1 = index_1 + 1;
				int next_index_2 = index_2;
				if (!visited[next_index_1][next_index_2] && graph[next_index_1][next_index_2] == 0) {
					graph[next_index_1][next_index_2] = 1;
					visited[next_index_1][next_index_2] = true;
					next_index.push_back(make_pair(next_index_1, next_index_2));
				}
			}
			//왼쪽
			if (index_2 - 1 >= 0) {
				int next_index_1 = index_1;
				int next_index_2 = index_2 - 1;
				if (!visited[next_index_1][next_index_2] && graph[next_index_1][next_index_2] == 0) {
					graph[next_index_1][next_index_2] = 1;
					visited[next_index_1][next_index_2] = true;
					next_index.push_back(make_pair(next_index_1, next_index_2));
				}
			}
			//오른쪽
			if (index_2 + 1 < width) {
				int next_index_1 = index_1;
				int next_index_2 = index_2 + 1;
				if (!visited[next_index_1][next_index_2] && graph[next_index_1][next_index_2] == 0) {
					graph[next_index_1][next_index_2] = 1;
					visited[next_index_1][next_index_2] = true;
					next_index.push_back(make_pair(next_index_1, next_index_2));
				}
			}

		}

		for (int i = 0; i < next_index.size(); i++) {
			pair<int, int> pair = make_pair(next_index[i].first,next_index[i].second);
			queue.push(pair);
		}

		next_index.clear();
		day++;

	}
	if (visited_order.size() == (width * height- empty_count)) {
		return day-1;
	}
	else {
		return -1;
	}

}


int main()
{
	int width, height;
	cin >> width >> height;
	
	vector<vector<int>> graph(height);
	vector<pair<int, int>> index;
	int empty_count = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int n;
			cin >> n;
			graph[i].push_back(n);
			if (n == 1) {
				index.push_back(make_pair(i,j));
			}
			else {
				if (n == -1)
					empty_count++;
			}
		}
	}
	if (index.size() == 0) {
		cout << -1 << endl;
	}
	else if (index.size() == width*height) {
		cout << 0 << endl;
	}
	else {
		int result = breath_first_search(graph, index, width, height,empty_count);
		cout << result << endl;
	}
	

	return 0;
}