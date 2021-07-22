#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void breath_first_search(vector<vector<int>>graph, pair<int,int> first_index, vector<vector<bool>>& visited, int width, int height) {
	queue<pair<int, int>> queue;

	queue.push(first_index);

	while (!queue.empty()) {
		int current_height = queue.front().first;
		int current_width = queue.front().second;

		queue.pop();
		if (!visited[current_height][current_width]) {
			visited[current_height][current_width] = true;

			//위
			if (current_height - 1 >= 0) {
				int next_height = current_height - 1;
				int next_width = current_width;
				if (graph[next_height][next_width] == 1 && !visited[next_height][next_width])
				{
					pair<int, int> next = make_pair(next_height,next_width);
					queue.push(next);
				}
			}

			//아래
			if (current_height + 1 < height) {
				int next_height = current_height + 1;
				int next_width = current_width;
				if (graph[next_height][next_width] == 1 && !visited[next_height][next_width])
				{
					pair<int, int> next = make_pair(next_height, next_width);
					queue.push(next);
				}
			}

			//오른쪽
			if (current_width + 1 < width) {
				int next_height = current_height;
				int next_width = current_width + 1;
				if (graph[next_height][next_width] == 1 && !visited[next_height][next_width])
				{
					pair<int, int> next = make_pair(next_height, next_width);
					queue.push(next);
				}
			}

			//왼쪽
			if (current_width - 1 >= 0) {
				int next_height = current_height;
				int next_width = current_width - 1;
				if (graph[next_height][next_width] == 1 && !visited[next_height][next_width])
				{
					pair<int, int> next = make_pair(next_height, next_width);
					queue.push(next);
				}
			}
		}
	}
}


int main()
{
	int textcase;
	vector<int> result;
	cin >> textcase;
	while (textcase) {
		int width, height, cabbage_count;
		int worm_count = 0;
		cin >> width >> height >> cabbage_count;
		vector<vector<int>> graph(height);
		vector<vector<bool>>visited(height);
		vector<pair<int, int>>index;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				graph[i].push_back(0);
				visited[i].push_back(false);
			}
		}
		
		
		
		for (int i = 0; i < cabbage_count; i++) {
			int index_width, index_height;
			cin >> index_width >> index_height;
			graph[index_height][index_width] = 1;
			index.push_back(make_pair(index_height,index_width));
		}
		
		
		int size = index.size();
		for (int i = 0; i < size; i++) {
			int height_index = index[i].first;
			int width_index = index[i].second;
			if (!visited[height_index][width_index]) {
				pair<int, int> first_index = make_pair(height_index,width_index);
				breath_first_search(graph,first_index,visited,width,height);
				worm_count++;
			}
		}

		result.push_back(worm_count);
		textcase--;
		graph.clear();
		visited.clear();
		index.clear();
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}