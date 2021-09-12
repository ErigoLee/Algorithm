#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 10000
using namespace std;
int hero_size = 2;
vector<vector<int>> graph;
int N = 0;
vector<vector<int>> distanceFind(int hero_x, int hero_y) {

	queue<tuple<int, int,int>> _queue;

	int graph_size = graph.size();
	vector<vector<int>> visited;
	vector<int> temp;
	for (int j = 0; j < N; j++) {
		temp.push_back(INF);
	}
	for (int i = 0; i < N; i++) {
		visited.push_back(temp);
	}
	visited[hero_x][hero_y] = 0;
	
	_queue.push(make_tuple(hero_x,hero_y,0));
	while (!_queue.empty()) {
		int index_x = get<0>(_queue.front());
		int index_y = get<1>(_queue.front());
		int now_distance = get<2>(_queue.front());
		_queue.pop();

		if (now_distance > visited[index_x][index_y])
			continue;

		if (hero_size >= graph[index_x][index_y]) {
			//up
			if (index_x - 1 >= 0) {
				int next_x = index_x - 1;
				int next_y = index_y;
				int next_distance = now_distance + 1;
				if (visited[next_x][next_y] > next_distance) {
					visited[next_x][next_y] = next_distance;
					_queue.push(make_tuple(next_x, next_y, next_distance));
				}
					
			}
			//down
			if (index_x + 1 < graph_size) {
				int next_x = index_x + 1;
				int next_y = index_y;
				int next_distance = now_distance + 1;
				if (visited[next_x][next_y] > next_distance) {
					visited[next_x][next_y] = next_distance;
					_queue.push(make_tuple(next_x, next_y, next_distance));
				}
					
			}
			//left
			if (index_y - 1 >= 0) {
				int next_x = index_x;
				int next_y = index_y - 1;
				int next_distance = now_distance + 1;
				if (visited[next_x][next_y] > next_distance) {
					visited[next_x][next_y] = next_distance;
					_queue.push(make_tuple(next_x, next_y, next_distance));
				}
			}
			//right
			if (index_y + 1 < graph_size) {
				int next_x = index_x;
				int next_y = index_y + 1;
				int next_distance = now_distance + 1;
				if (visited[next_x][next_y] > next_distance) {
					visited[next_x][next_y] = next_distance;
					_queue.push(make_tuple(next_x, next_y, next_distance));
				}
			}
		}

	}

	return visited;
}


int solution(vector<pair<int,int>> fish_places, pair<int, int> hero_place) {

	int eating = 0;
	int hero_x = hero_place.first;
	int hero_y = hero_place.second;
	int timer = 0;
	int size = fish_places.size();
	graph[hero_x][hero_y] = 0;
	while (true) {
		int distance = INF;
		if (size == 0)
			break;
		int eating_fish_x = -1;
		int eating_fish_y = -1;
		vector<vector<int>> distances = distanceFind(hero_x, hero_y);
		for (auto fish_place : fish_places) {
			int first_index = fish_place.first;
			int second_index = fish_place.second;
			
			if (hero_size > graph[first_index][second_index] && graph[first_index][second_index] > 0) {
				
				if (distance > distances[first_index][second_index]) {
					distance = distances[first_index][second_index];
					eating_fish_x = first_index;
					eating_fish_y = second_index;
				}
				
				if (distance == distances[first_index][second_index]) {
					if (first_index < eating_fish_x) {
						eating_fish_x = first_index;
						eating_fish_y = second_index;
					}
					else {
						if (eating_fish_x == first_index) {
							if (second_index < eating_fish_y) {
								eating_fish_x = first_index;
								eating_fish_y = second_index;
							}
						}
					}
				}
			}	
		}

		if (eating_fish_x != -1 && eating_fish_y != -1) {
			eating++;
			timer += distance;
			hero_x = eating_fish_x;
			hero_y = eating_fish_y;
			size--;
			graph[eating_fish_x][eating_fish_y] = 0;
			if (hero_size == eating) {
				hero_size++;
				eating = 0;
			}
		}
		else {
			break;
		}
	}

	return timer;

}



int main() {

	cin >> N;
	int fish_count = 0;
	vector<pair<int, int>> fish_places;
	pair<int, int> hero_place;
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			if (a > 0 && a < 9) {
				fish_count++;
				pair<int, int> fish_place = make_pair(i,j);
				fish_places.push_back(fish_place);
			}
			
			if (a == 9) {
				hero_place = make_pair(i,j);
			}
				
			temp.push_back(a);
		}
		graph.push_back(temp);
		temp.clear();
	}
	if (fish_count == 0)
		cout << 0 << endl;
	else {
		int result = solution(fish_places,hero_place);
		cout << result << endl;
	}
	return 0;
}