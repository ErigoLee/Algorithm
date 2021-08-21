#include <iostream>
#include <cmath>
#define INF 124751
using namespace std;


int down_graph[501][501];
int up_graph[501][501];

int main() {
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
			{
				down_graph[i][j] = 0;
				up_graph[i][j] = 0;
			}
			else {
				down_graph[i][j] = INF;
				up_graph[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int to, from;
		cin >> to >> from;
		up_graph[to][from] = 1;
		down_graph[from][to] = 1;
	}


	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				down_graph[i][j] = min(down_graph[i][j],down_graph[i][k]+down_graph[k][j]);
				up_graph[i][j] = min(up_graph[i][j],up_graph[i][k]+up_graph[k][j]);
			}
		}
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		int count_2 = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			if (down_graph[i][j] != INF) {
				count_2++;
			}
			if (up_graph[i][j] != INF) {
				count_2++;
			}
		}
		if (count_2 >= N-1) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}