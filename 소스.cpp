#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int count;
	vector<int> thinkingNum = vector<int>();
	cin >> count;

	int* N = new int[count];
	int* strike = new int[count];
	int* ball = new int[count];
	int possible_Count = 0;

	for (int i = 0; i < count; i++) {
		cin >> N[i] >> strike[i] >> ball[i];
	}


	int c_100 = N[0] / 100;
	int c_10 = (N[0] - c_100 * 100) / 10;
	int c_1 = (N[0] - c_100 * 100 - c_10 * 10);



	if (strike[0] == 0)
	{
		if (ball[0] == 0)
		{
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				for (int j = 1; j < 10; j++) {
					if (c_100 == j || c_10 == j || c_1 == j)
						continue;
					if (i == j)
						continue;
					for (int k = 1; k < 10; k++) {
						if (c_100 == k || c_10 == k || c_1 == k)
							continue;
						if (i == k || j == k)
							continue;
						thinkingNum.push_back(i * 100 + j * 10 + k);
					}
				}
			}
		}
		else if (ball[0] == 1) {

			//c_100 ball - 1자리
			for (int i = 1; i < 10; i++) {

				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				for (int j = 1; j < 10; j++) {
					if (c_100 == j || c_10 == j || c_1 == j)
						continue;
					if (i == j)
						continue;
					thinkingNum.push_back(i * 100 + j * 10 + c_100);
				}
			}
			//c_100 ball - 십자리
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				for (int j = 1; j < 10; j++) {
					if (c_100 == j || c_10 == j || c_1 == j)
						continue;
					if (i == j)
						continue;
					thinkingNum.push_back(i * 100 + c_100 * 10 + j);
				}
			}





			//c_10 ball - 1자리
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				for (int j = 1; j < 10; j++) {
					if (c_100 == j || c_10 == j || c_1 == j)
						continue;
					if (i == j)
						continue;
					thinkingNum.push_back(i * 100 + j * 10 + c_10);
				}
			}


			//c_10 ball -백자리
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				for (int j = 1; j < 10; j++) {
					if (c_100 == j || c_10 == j || c_1 == j)
						continue;
					if (i == j)
						continue;
					thinkingNum.push_back(c_10 * 100 + i * 10 + j);
				}
			}



			//c_1 ball-백자리
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				for (int j = 1; j < 10; j++) {
					if (c_100 == j || c_10 == j || c_1 == j)
						continue;
					if (i == j)
						continue;
					thinkingNum.push_back(c_1 * 100 + i * 10 + j);
				}
			}
			//c_1 ball-십자리
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				for (int j = 1; j < 10; j++) {
					if (c_100 == j || c_10 == j || c_1 == j)
						continue;
					if (i == j)
						continue;
					thinkingNum.push_back(i * 100 + c_1 * 10 + j);
				}
			}

		}
		else if (ball[0] == 2) {

			//ball2일 경우
			//c_100,c_10
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;

				// 백 c_10, 십 c_100
				thinkingNum.push_back(c_10 * 100 + c_100 * 10 + i);

				// 백 c_10, 일 c_100
				thinkingNum.push_back(c_10 * 100 + i * 10 + c_100);

				// 일 c_10, 십 c_100
				thinkingNum.push_back(i * 100 + c_100 * 10 + c_10);

			}
			//c_100,c_1
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;

				//백 c_1, 십 c_100
				thinkingNum.push_back(c_1 * 100 + c_100 * 10 + i);

				//백 c_1, 일 c_100
				thinkingNum.push_back(c_1 * 100 + i * 10 + c_100);

				//십 c_1, 일 c_100
				thinkingNum.push_back(i * 100 + c_1 * 10 + c_100);

			}
			//c_10,c_1
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;

				//백 c_10 십 c_1
				thinkingNum.push_back(c_10 * 100 + c_1 * 10 + i);

				//일 c_10 백 c_1
				thinkingNum.push_back(c_1 * 100 + i * 10 + c_10);

				//일 c_10 십 c_1
				thinkingNum.push_back(i * 100 + c_1 * 10 + c_10);
			}

		}
		else {
			//ball3일 경우

			thinkingNum.push_back(c_1 * 100 + c_100 * 10 + c_10);
			thinkingNum.push_back(c_10 * 100 + c_1 * 10 + c_100);
		}

	}
	else if (strike[0] == 1) {
		if (ball[0] == 0)
		{
			//c_100
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				for (int j = 1; j < 10; j++) {
					if (c_100 == j || c_10 == j || c_1 == j)
						continue;
					if (i == j)
						continue;
					thinkingNum.push_back(c_100 * 100 + i * 10 + j);
				}
			}

			//c_10
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				for (int j = 1; j < 10; j++) {
					if (c_100 == j || c_10 == j || c_1 == j)
						continue;
					if (i == j)
						continue;
					thinkingNum.push_back(i * 100 + c_10 * 10 + j);
				}
			}

			//c_1

			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				for (int j = 1; j < 10; j++) {
					if (c_100 == j || c_10 == j || c_1 == j)
						continue;
					if (i == j)
						continue;
					thinkingNum.push_back(i * 100 + j * 10 + c_1);
				}
			}
		}
		else if (ball[0] == 1) {
			//strike c_100 , ball c_10

			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				thinkingNum.push_back(c_100 * 100 + i * 10 + c_10);

			}

			//strike c_100 , ball c_1
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				thinkingNum.push_back(c_100 * 100 + c_1 * 10 + i);

			}

			//strike c_10, ball c_100
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				thinkingNum.push_back(i * 100 + c_10 * 10 + c_100);

			}

			//strike c_10, ball c_1
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				thinkingNum.push_back(c_1 * 100 + c_10 * 10 + i);

			}

			//strike c_1, ball c_100
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				thinkingNum.push_back(i * 100 + c_100 * 10 + c_1);

			}

			//strike c_1, ball c_10
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				thinkingNum.push_back(c_10 * 100 + i * 10 + c_1);

			}
		}
		else {
			//ball[0] == 2

			//strike c_100
			thinkingNum.push_back(c_100 * 100 + c_1 * 10 + c_10);

			//strike c_10
			thinkingNum.push_back(c_1 * 100 + c_10 * 10 + c_100);

			//strike c_1
			thinkingNum.push_back(c_10 * 100 + c_100 * 10 + c_1);
		}
	}
	else if (strike[0] == 2) {
		if (ball[0] == 0)
		{

			//stricke c_100,c_10
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				thinkingNum.push_back(c_100 * 100 + c_10 * 10 + i);
			}

			//stricke c_100,c_1
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				thinkingNum.push_back(c_100 * 100 + i * 10 + c_1);
			}


			//stricke c_10,c_1
			for (int i = 1; i < 10; i++) {
				if (c_100 == i || c_10 == i || c_1 == i)
					continue;
				thinkingNum.push_back(i * 100 + c_10 * 10 + c_1);
			}
		}

	}
	else {
		//strike3인경우
		possible_Count = 1;
		cout << possible_Count << endl;
		return 0;
	}

	vector<bool> checking = vector<bool>();
	for (int i = 0; i < thinkingNum.size(); i++) {
		checking.push_back(true);
	}


	for (int i = 1; i < count; i++) {
		int check_100 = N[i] / 100;
		int check_10 = (N[i] - check_100 * 100) / 10;
		int check_1 = (N[i] - check_100 * 100 - check_10 * 10);
		for (int j = 0; j < thinkingNum.size(); j++) {
			if (checking[j] == false)
				continue;

			int think_100 = thinkingNum[j] / 100;
			int think_10 = (thinkingNum[j] - think_100 * 100) / 10;
			int think_1 = (thinkingNum[j] - think_100 * 100 - think_10 * 10);

			int think_ball = 0;
			int think_strike = 0;

			if (think_100 == check_100)
				think_strike++;
			else {
				if (think_100 == check_10 || think_100 == check_1)
					think_ball++;
			}

			if (think_10 == check_10)
				think_strike++;
			else {
				if (think_10 == check_100 || think_10 == check_1)
					think_ball++;
			}

			if (think_1 == check_1)
				think_strike++;
			else {
				if (think_1 == check_100 || think_1 == check_10)
					think_ball++;
			}
			if (think_ball != ball[i] || think_strike != strike[i])
				checking[j] = false;

		}

	}

	for (int i = 0; i < checking.size(); i++) {
		if (checking[i] == true)
			possible_Count++;
	}

	cout << possible_Count << endl;

	return 0;
}