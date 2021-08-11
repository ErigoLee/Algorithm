#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

	int testcase;
	cin >> testcase;
	vector<string> answer;
	for (int i = 0; i < testcase; i++) {
		int count;
		string input_str;
		cin >> count >> input_str;
		string answer_str="";
		for (int j = 0; j < input_str.size(); j++) {
			for (int k = 0; k < count; k++) {
				answer_str += input_str[j];
			}
		}
		answer.push_back(answer_str);
	}
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	
	return 0;
}