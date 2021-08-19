#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define INF 9999999999
using namespace std;
long long _max = 0;
string max_str = "";
bool max_check = false;
long long _min = INF;
string min_str = "";
bool min_check = false;


void maxSearch(int start, int dept, int pos, string condition, bool check[10],vector<int>result) {

	if (pos >= dept) {
		long long num = 0;
		for (int i = 0; i < result.size(); i++) {
			num += (long long)result[i] * (long long)pow(10, result.size() - i - 1);
		}
		if (num > _max) {
			_max = num;
			if (result[0] == 0) {
				max_str = '0'+to_string(num);
			}
			else {
				max_str = to_string(num);
			}
			
			max_check = true;
		}

		return;
	}
	if (condition[pos] == '>') {
		for (int i = start; i > -1; i--) {
			if (!check[i]) {
				check[i] = true;
				result.push_back(i);
				maxSearch(i, dept, pos + 1, condition, check , result);
				result.pop_back();
				check[i] = false;
			}
		}
	}
	else {
		for (int i = start; i < 10; i++) {
			if (!check[i]) {
				check[i] = true;
				result.push_back(i);
				maxSearch(i, dept, pos + 1, condition, check, result);
				result.pop_back();
				check[i] = false;
			}
		}
	}

}


void minSearch(int start, int dept, int pos, string condition, bool check[10], vector<int> result) {

	if (pos >= dept) {
		long long num = 0;
		for (int i = 0; i < result.size(); i++) {
			num += (long long)result[i] * (long long)pow(10,result.size()-i-1);
		}
		if (_min > num) {
			_min = num;
			if (result[0] == 0) {
				min_str = '0' + to_string(num);
			}
			else {
				min_str = to_string(num);
			}
			min_check = true;
		}

		return;
	}

	if (condition[pos] == '>') {
		for (int i = start; i > -1; i--) {
			if (!check[i]) {
				check[i] = true;
				result.push_back(i);
				minSearch(i,dept,pos+1,condition, check, result);
				result.pop_back();
				check[i] = false;
			}
		}
	}
	else {
		for (int i = start; i < 10; i++) {
			if (!check[i]) {
				check[i] = true;
				result.push_back(i);
				minSearch(i, dept, pos + 1, condition, check, result);
				result.pop_back();
				check[i] = false;
			}
		}
	}

}

int main() {
	int cnt;
	string condition;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		char a;
		cin >> a;
		condition.push_back(a);
	}
	
	bool check[10] = { false, false, false, false, false,false,false, false,false, false };
	for (int i = 0; i <= 9; i++) {
		check[i] = true;
		vector<int> a;
		a.push_back(i);
		minSearch(i,cnt,0,condition,check,a);
		a.pop_back();
		check[i] = false;
		if (min_check)
			break;
	}
	for (int i = 9; i > -1; i--) {
		check[i] = true;
		vector<int> a;
		a.push_back(i);
		maxSearch(i,cnt,0,condition, check,a);
		a.pop_back();
		check[i] = false;
		if (max_check)
			break;
	}
	
	cout << max_str << endl;
	cout << min_str << endl;
	
	return 0;
}
