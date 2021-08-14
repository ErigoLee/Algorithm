#include <iostream>
#include <vector>

using namespace std;

//세로 방향
bool colCheck(vector<vector<int>> col, int N, int L, int num) {

	vector<bool> col_use;
	for (int i = 0; i < N; i++) {
		col_use.push_back(false);
	}


	for (int i = 0; i < N; i++) {
		if (i + 1 < N) {
			if (col[i][num] < col[i + 1][num]) {
				if (col[i + 1][num] - col[i][num] > 1)
					return false;
				else {
					if (col_use[i] == true)
						return false;
					col_use[i] = true;
					for (int k = 1; k < L; k++) {
						if (i - k < 0)
							return false;
						else {
							if (col_use[i - k] == true)
								return false;
							if (col[i - k][num] != col[i][num])
								return false;
							else {
								col_use[i - k] = true;
							}
						}

					}
				}
			}
			if (col[i][num] > col[i + 1][num]) {
				if (col[i][num] - col[i + 1][num] > 1)
					return false;
				else {
					if (col_use[i + 1] == true)
						return false;
					col_use[i + 1] = true;
					for (int k = 1; k < L; k++) {
						if (i + 1 + k >= N)
							return false;
						else {
							if (col_use[i + 1 + k] == true)
								return false;
							if (col[i + 1 + k][num] != col[i + 1][num])
								return false;
							else {
								col_use[i + 1 + k] = true;
							}
						}
					}
					i += (L-1);
				}
			}
		}
	}
	return true;
}



//가로 방향
bool rowCheck(vector<int> row, int N, int L)
{
	vector<bool> row_use;

	for (int i = 0; i < N; i++) {
		row_use.push_back(false);
	}


	for (int i = 0; i < N; i++) {
		if (i + 1 < N) {
			if (row[i] < row[i + 1]) {
				if (row[i + 1] - row[i] > 1)
					return false;
				else {
					if (row_use[i] == true)
						return false;
					row_use[i] = true;
					for (int k = 1; k < L; k++) {
						if (i - k < 0)
							return false;
						else {
							if (row_use[i - k] == true)
								return false;

							if (row[i - k] != row[i])
								return false;
							else {
								row_use[i - k] = true;
							}
								
						}
					}
				}
			}
			if (row[i] > row[i + 1]) {
				if (row[i] - row[i + 1] > 1)
					return false;
				else {
					if (row_use[i + 1] == true)
						return false;
					row_use[i + 1] = true;
					for (int k = 1; k < L; k++) {
						if (i + 1 + k >= N)
							return false;
						else {
							if (row_use[i + 1 + k] == true)
								return false;

							if (row[i + 1 + k] != row[i + 1])
								return false;
							else {
								row_use[i + 1 + k] = true;
							}
						}
					}
					i += (L-1);
				}
			}
		}
	}
	return true;
}


int main() {

	int N, L;
	vector<vector<int>> graph;
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			temp.push_back(a);
		}
		graph.push_back(temp);
		temp.clear();
	}

	int count = 0;
	//cout << "row" << endl;
	//가로 방향
	for (int i = 0; i < N; i++) {
		bool check = rowCheck(graph[i], N, L);
		
		if (check) {
			count++;
			//cout << i << " " << count << endl;
		}
			
	}

	//세로 방향
	//cout << "col" << endl;
	for (int i = 0; i < N; i++) {
		bool check = colCheck(graph, N, L, i);
		
		if (check) {
			count++;
			//cout << i << " " << count << endl;
		}
			
	}
	cout << count << endl;
	return 0;
}