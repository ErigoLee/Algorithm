#include <iostream>
#include <string>
#include <vector>

using namespace std;
//k->Ãþ n->È£
int home(int k, int n) {
	if (k == 0) {
		return n;
	}
	else {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += home(k-1,i);
		}
		return sum;
	}
}



int main() {

	int T;
	cin >> T;
	vector<int> answer;
	for (int i = 0; i < T; i++) {
		int k, n;
		cin >> k >> n;
		int an = home(k,n);
		answer.push_back(an);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}