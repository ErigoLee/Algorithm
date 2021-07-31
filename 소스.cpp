#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define INF 1000000000
using namespace std;

int dijkstra(vector<vector<int>> graph, int start_1,int start_2) {

	int height = graph.size();
	int width = graph[0].size();
	//cost
	vector<vector<int>> cost;
	queue<pair<int, int>> queue;
	for (int i = 0; i < height; i++) {
		vector<int> row;
		for (int j = 0; j < width; j++) {
			row.push_back(INF);
		}
		cost.push_back(row);
		row.clear();
	}

	cost[start_1][start_2] = 0;
	queue.push(make_pair(start_1,start_2));

	while (!queue.empty()) {
		int current_h = queue.front().first;
		int current_w = queue.front().second;

		queue.pop();

		//왼쪽
		if (current_w - 1>=0) {
			int next_h = current_h;
			int next_w = current_w - 1;
			if (cost[next_h][next_w] > cost[current_h][current_w] + graph[next_h][next_w]) {
				cost[next_h][next_w] = cost[current_h][current_w] + graph[next_h][next_w];
				queue.push(make_pair(next_h,next_w));
			}

		}

		//오른쪽
		if (current_w + 1 < width) {
			int next_h = current_h;
			int next_w = current_w + 1;
			if (cost[next_h][next_w] > cost[current_h][current_w] + graph[next_h][next_w]) {
				cost[next_h][next_w] = cost[current_h][current_w] + graph[next_h][next_w];
				queue.push(make_pair(next_h, next_w));
			}
		}

		//위
		if (current_h - 1 >= 0) {
			int next_h = current_h - 1;
			int next_w = current_w;
			if (cost[next_h][next_w] > cost[current_h][current_w] + graph[next_h][next_w]) {
				cost[next_h][next_w] = cost[current_h][current_w] + graph[next_h][next_w];
				queue.push(make_pair(next_h, next_w));
			}
		}
		//아래
		if (current_h + 1 < height) {
			int next_h = current_h + 1;
			int next_w = current_w;
			if (cost[next_h][next_w] > cost[current_h][current_w] + graph[next_h][next_w]) {
				cost[next_h][next_w] = cost[current_h][current_w] + graph[next_h][next_w];
				queue.push(make_pair(next_h, next_w));
			}
		}

	}


	return cost[height - 1][width - 1];

}





int main() {

	int width, height;
	vector<vector<int>> graph;
	int result;

	cin >> width >> height;
	

	for (int i = 0; i < height; i++) {
		vector<int> row;
		string input_value;
		cin >> input_value;
		for (int j = 0; j < width; j++) {
			int n = (int)input_value[j] - 48;
			row.push_back(n);
		}
		graph.push_back(row);
		row.clear();
	}
	
	result = dijkstra(graph,0,0);
	cout << result << endl;

	return 0;
}
