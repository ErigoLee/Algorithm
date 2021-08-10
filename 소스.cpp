#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int testcase;
	int H, W, N;
	cin >> testcase;
	
	
	vector<int> answer;

	for (int k = 0; k < testcase; k++) {
		int count = 0;
		cin >> H >> W >> N;
		bool check = false;
		int answer_H = 0;
		int answer_W = 0;
		for (int i = 1; i <= W; i++) {
			for (int j = 1; j <= H; j++) {
				count++;
				if (count == N)
				{
					answer_W = i;
					answer_H = j;
					check = true;
					break;
				}
			}
			if (check) {
				break;
			}
		}

		answer.push_back(answer_H*100+answer_W);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	return 0;
}