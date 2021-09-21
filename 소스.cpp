#include <iostream>
#include <string>
#include <vector>
#define INF 100000001

using namespace std;
int N;
int max_depth;
vector<vector<bool>> checking_list;
void Combination(int index, int depth, vector<bool> checking) {

	if (depth == max_depth) {
		checking_list.push_back(checking);
	}
	else {
		for (int i = index; i < N; i++) {
			checking[i] = true;
			Combination(i+1,depth+1,checking);
			checking[i] = false;
		}
	}


}

int main() {
	
	cin >> N;
	max_depth = N / 2;
	vector<vector<int>> graph;
	
	vector<bool> checking;
	for (int i = 0; i < N; i++)
		checking.push_back(false);

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

	Combination(0,0,checking);
	int size = checking_list.size();
	int min = INF;
	for (int i = 0; i < size; i++) {
		int value = 0; //true
		int value2 = 0; //false
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (j == k)
					continue;
				else {
					if (checking_list[i][j] == checking_list[i][k]) {
						if (checking_list[i][k] == true) {
							value += graph[j][k];
						}
						else {
							value2 += graph[j][k];
						}
					}
				}
			}
		}
		if (value < value2) {
			int temp = value2 - value;
			if (min > temp)
				min = temp;
		}
		else {
			int temp = value - value2;
			if (min > temp)
				min = temp;
		}

	}

	cout << min << endl;

	return 0;
}