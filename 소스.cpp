#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int graph_sum(vector<vector<int>> graph, int R, int C) {
	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			sum += graph[i][j];
		}
	}
	return sum;
}

vector<vector<int>> clearing(vector<vector<int>>graph, vector<pair<int, int>>clear,int R, int C) {
	
	vector<vector<int>> dummy;

	for (int i = 0; i < R; i++) {
		vector<int> temp;
		for (int j = 0; j < C; j++) {
			temp.push_back(0);
		}
		dummy.push_back(temp);
		temp.clear();
	}

	//위
	pair<int, int> up = clear[0];
	pair<int, int> index;
	int stage = 0;
	if (up.second + 1 >= C) {
		stage = 1;
		index = make_pair(up.first-1,up.second);
	}
	else {
		stage = 0;
		index = make_pair(up.first, up.second + 1);
	}

	
	while (true) {
		int n = index.first;
		int m = index.second;

		if (up.first == n && up.second == m)
			break;

		if (stage == 0) {
			if (index.second + 1 >= C) {
				index = make_pair(n-1,m);
				dummy[n - 1][m] = graph[n][m];
				stage = 1;
			}
			else {
				index = make_pair(n,m+1);
				dummy[n][m + 1] = graph[n][m];
			}
		}
		else if (stage == 1) {
			if (index.first - 1 < 0) {
				index = make_pair(n,m-1);
				dummy[n][m - 1] = graph[n][m];
				stage = 2;
			}
			else {
				index = make_pair(n-1,m);
				dummy[n - 1][m] = graph[n][m];
			}
		}
		else if (stage == 2) {
			if (index.second - 1 < 0) {
				index = make_pair(n+1,m);
				dummy[n + 1][m] = graph[n][m];
				stage = 3;
			}
			else {
				index = make_pair(n,m-1);
				dummy[n][m - 1] = graph[n][m];
			}
		}
		else if (stage == 3) {
			if (index.first + 1 > up.first) {
				index = make_pair(n,m+1);
				dummy[n][m + 1] = graph[n][m];
				stage = 4;
			}
			else {
				index = make_pair(n+1,m);
				dummy[n + 1][m] = graph[n][m];
			}
		}
		else {
			index = make_pair(n,m+1);
			dummy[n][m + 1] = graph[n][m];
		}
	}
	
	//아래
	pair<int, int> down = clear[1];
	if (down.second + 1 >= C) {
		stage = 1;
		index = make_pair(down.first + 1, down.second);
	}
	else {
		stage = 0;
		index = make_pair(down.first, down.second + 1);
	}
	while (true) {
		int n = index.first;
		int m = index.second;

		if (down.first == n && down.second == m)
			break;

		if (stage == 0) {
			if (index.second + 1 >= C) {
				index = make_pair(n + 1, m);
				dummy[n + 1][m] = graph[n][m];
				stage = 1;
			}
			else {
				index = make_pair(n, m + 1);
				dummy[n][m + 1] = graph[n][m];
			}
		}
		else if (stage == 1) {
			if (index.first + 1 >= R) {
				index = make_pair(n, m - 1);
				dummy[n][m - 1] = graph[n][m];
				stage = 2;
			}
			else {
				index = make_pair(n + 1, m);
				dummy[n + 1][m] = graph[n][m];
			}
		}
		else if (stage == 2) {
			if (index.second - 1 < 0) {
				index = make_pair(n - 1, m);
				dummy[n - 1][m] = graph[n][m];
				stage = 3;
			}
			else {
				index = make_pair(n, m - 1);
				dummy[n][m - 1] = graph[n][m];
			}
		}
		else if (stage == 3) {
			if (index.first - 1 < down.first) {
				index = make_pair(n, m + 1);
				dummy[n][m + 1] = graph[n][m];
				stage = 4;
			}
			else {
				index = make_pair(n - 1, m);
				dummy[n - 1][m] = graph[n][m];
			}
		}
		else {
			index = make_pair(n, m + 1);
			dummy[n][m + 1] = graph[n][m];
		}
	}
	dummy[up.first][up.second] = -1;
	dummy[down.first][down.second] = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (dummy[i][j] == 0 && graph[i][j] > 0) {
				if ((i != up.first)&&(i!=down.first)&&(i != 0) &&(i != R-1) && (j != up.second) &&(j != C-1)) {
					dummy[i][j] = graph[i][j];
				}
			}
		}
	}
	return dummy;
}



vector<vector<int>> diffusion(vector<vector<int>>graph, int R, int C) {

	vector<vector<int>> dummy;

	for (int i = 0; i < R; i++) {
		vector<int> temp;
		for (int j = 0; j < C; j++) {
			temp.push_back(0);
		}
		dummy.push_back(temp);
		temp.clear();
	}



	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] > 0) {
				int dust = graph[i][j] / 5;
				int direction = 0;
				//위
				if (i - 1 >= 0) {
					if (graph[i - 1][j] >= 0) {
						dummy[i - 1][j] += dust;
						direction++;
					}
				}
				//아래
				if (i + 1 < R) {
					if (graph[i + 1][j] >= 0) {
						dummy[i + 1][j] += dust;
						direction++;
					}
				}
				//왼쪽
				if (j - 1 >= 0) {
					if (graph[i][j - 1] >= 0) {
						dummy[i][j - 1] += dust;
						direction++;
					}
				}
				//오른쪽
				if (j + 1 < C) {
					if (graph[i][j + 1] >= 0) {
						dummy[i][j + 1] += dust;
						direction++;
					}
				}

				graph[i][j] = graph[i][j] - dust * direction;
			}
		}
	}


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			graph[i][j] += dummy[i][j];
		}
	}

	return graph;
}





int main() {

	int R, C, T;
	cin >> R >> C >> T;

	vector<vector<int>> graph;
	vector<pair<int, int>> clear;
	int result = 0;

	for (int i = 0; i < R; i++) {
		vector<int> temp;
		for (int j = 0; j < C; j++) {
			int n;
			cin >> n;
			if (n == -1) {
				clear.push_back(make_pair(i,j));
			}
			temp.push_back(n);
		}
		graph.push_back(temp);
		temp.clear();
	}

	for (int i = 0; i < T; i++) {
		graph = diffusion(graph,R,C);
		graph = clearing(graph,clear,R,C);
	}

	result = graph_sum(graph,R,C) + 2;
	cout << result << endl;

	return 0;
}