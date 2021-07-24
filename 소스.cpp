#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int breadth_first_search(vector<vector<vector<int>>> graph,vector<tuple<int,int,int>> index, int empty_count,int M,int N, int H) {

	queue<tuple<int, int, int>> queue;
	vector<tuple<int, int, int>> visited_order;
	int day = -1;
	
	for (int i = 0; i < index.size(); i++) {
		tuple<int, int, int> tuple = make_tuple(get<0>(index[i]),get<1>(index[i]),get<2>(index[i]));
		queue.push(tuple);
	}


	while (!queue.empty()) {
		int size = queue.size();
		vector<tuple<int, int, int>> next;
		for (int i = 0; i < size; i++) {
			int index_1 = get<0>(queue.front());
			int index_2 = get<1>(queue.front());
			int index_3 = get<2>(queue.front());
	
			queue.pop();
			visited_order.push_back(make_tuple(index_1,index_2,index_3));

			//위  N
			if (index_2 - 1 > -1) {
				int next_index_1 = index_1;
				int next_index_2 = index_2 -1;
				int next_index_3 = index_3;
				if (graph[next_index_1][next_index_2][next_index_3] == 0) {
					graph[next_index_1][next_index_2][next_index_3] = 1;
					next.push_back(make_tuple(next_index_1, next_index_2, next_index_3));
				}

			}

			//아래
			if (index_2 + 1 < N) {
				int next_index_1 = index_1;
				int next_index_2 = index_2 + 1;
				int next_index_3 = index_3;
				if (graph[next_index_1][next_index_2][next_index_3] == 0) {
					graph[next_index_1][next_index_2][next_index_3] = 1;
					next.push_back(make_tuple(next_index_1, next_index_2, next_index_3));
				}
			}


			//왼쪽 M
			if (index_3 - 1 > -1) {
				int next_index_1 = index_1;
				int next_index_2 = index_2;
				int next_index_3 = index_3-1;
				if (graph[next_index_1][next_index_2][next_index_3] == 0) {
					graph[next_index_1][next_index_2][next_index_3] = 1;
					next.push_back(make_tuple(next_index_1, next_index_2, next_index_3));
				}
			}

			//오른쪽
			if (index_3 + 1 < M) {
				int next_index_1 = index_1;
				int next_index_2 = index_2;
				int next_index_3 = index_3 + 1;
				if (graph[next_index_1][next_index_2][next_index_3] == 0) {
					graph[next_index_1][next_index_2][next_index_3] = 1;
					next.push_back(make_tuple(next_index_1, next_index_2, next_index_3));
				}
			}
			//앞 H
			if (index_1 + 1 < H) {
				int next_index_1 = index_1 + 1;
				int next_index_2 = index_2;
				int next_index_3 = index_3;
				if (graph[next_index_1][next_index_2][next_index_3] == 0) {
					graph[next_index_1][next_index_2][next_index_3] = 1;
					next.push_back(make_tuple(next_index_1, next_index_2, next_index_3));
				}
			}

			//뒤 
			if (index_1 - 1 > -1) {
				int next_index_1 = index_1 -1;
				int next_index_2 = index_2;
				int next_index_3 = index_3;
				if (graph[next_index_1][next_index_2][next_index_3] == 0) {
					graph[next_index_1][next_index_2][next_index_3] = 1;
					next.push_back(make_tuple(next_index_1, next_index_2, next_index_3));
				}
			}

		}

		for (int i = 0; i < next.size(); i++) {
			queue.push(make_tuple(get<0>(next[i]), get<1>(next[i]), get<2>(next[i])));
		}
		next.clear();
		day++;
	}
	
	if (visited_order.size() == (N * M * H - empty_count)) {
		return day;
	}
	else {
		return -1;
	}

	

}




int main()
{
	int M, N, H;
	cin >> M >> N >> H;

	vector<vector<vector<int>>> graph;
	int empty_count = 0;
	vector<tuple<int, int, int>> index;

	for (int i = 0; i < H; i++) {
		vector<vector<int>> box;
		for (int j = 0; j < N; j++) {
			vector<int> row;
			for (int k = 0; k < M; k++) {
				int n;
				cin >> n;
				row.push_back(n);
				if (n == -1) {
					empty_count++;
				}
				if (n == 1) {
					index.push_back(make_tuple(i,j,k));
				}
			}
			box.push_back(row);
			row.clear();
		}
		graph.push_back(box);
		box.clear();
	}
	
	if (index.size() == (M * N * H-empty_count)) {
		cout << 0 << endl;
	}
	else {
		int result = breadth_first_search(graph,index,empty_count,M,N,H);
		cout << result << endl;
	}
	
	
	return 0;
}