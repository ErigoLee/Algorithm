#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> numbers;
	vector<char> cal;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}
	int plus, sub, multi, divi;
	cin >> plus >> sub >> multi >> divi;
	for (int i = 0; i < plus; i++) {
		cal.push_back('+');
	}
	for (int i = 0; i < sub; i++) {
		cal.push_back('-');
	}
	for (int i = 0; i < multi; i++) {
		cal.push_back('*');
	}
	for (int i = 0; i < divi; i++) {
		cal.push_back('/');
	}
	
	int answerMIN = INF;
	int answerMAX = -INF;
	sort(cal.begin(),cal.end());
	int size = cal.size();
	
	do {
		int answer = numbers[0];
		for (int i = 0; i < size; i++) {
			switch (cal[i])
			{
			case '+':
				answer = answer + numbers[i + 1];
				break;
			case '-':
				answer = answer - numbers[i + 1];
				break;
			case '*':
				answer = answer * numbers[i + 1];
				break;
			case '/':
				answer = answer / numbers[i + 1];
				break;
			}
		}
		answerMIN = min(answer, answerMIN);
		answerMAX = max(answer, answerMAX);

	} while (next_permutation(cal.begin(), cal.end()));
		
	cout << answerMAX << endl;
	cout << answerMIN << endl;
	return 0;
}