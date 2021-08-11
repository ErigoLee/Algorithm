#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<vector<string>> star;

	bool check = false;
	for (int i = 0; i < N * 2; i++) {
		vector<string> temp;
		if (i % 2 == 0)
		{
			check = true;
		}
		else {
			check = false;
		}
		for (int j = 0; j < N; j++) {
			if (check) {
				if (j % 2 == 0) {
					string a = "*";
					temp.push_back(a);
				}
				else {
					string a = " ";
					temp.push_back(a);
				}
			}
			else {
				if (j % 2 == 0) {
					string a = " ";
					temp.push_back(a);
				}
				else {
					string a = "*";
					temp.push_back(a);
				}
			}
		}
		star.push_back(temp);
		temp.clear();
	}

	if (N == 1) {
		star.clear();
		vector<string> temp;
		temp.push_back("*");
		star.push_back(temp);
	}


	for (int i = 0; i < star.size(); i++) {
		for (int j = 0; j < star[0].size(); j++) {
			cout << star[i][j];
		}
		cout << endl;
	}
	
	return 0;
}