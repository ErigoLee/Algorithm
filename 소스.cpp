#include <iostream>

using namespace std;

int sum;

bool check(int** arr,int length) {
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++) {
			if (arr[i][j] == 0) {
				return false;
			}
		}
		
	}
	return true;
}
bool check2(int** arr, int length) {
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++) {
			if (arr[i][j] == 1) {
				return false;
			}
		}

	}
	return true;
}

int divide(int** arr, int w_left, int w_right, int h_left, int h_right,int length , bool isblue) {
	
	int w_mid;
	int h_mid;

	int** new_arr = new int* [length];
	int width = w_left;
	int height = h_left;
	for (int i = 0; i < length; i++)
	{
		new_arr[i] = new int[length];
		for (int j = 0; j < length; j++)
		{
			new_arr[i][j] = arr[width][height++];
		}
		width++;
		height = h_left;
	}
	bool pass;
	if (isblue) {
		pass = check(new_arr, length);
	}
	else {
		pass = check2(new_arr, length);
	}
	 

	if (pass) {
		return 1;
	}
		
	if (w_left < w_right)
	{

		w_mid = (w_left + w_right) / 2;
		h_mid = (h_left + h_right) / 2;

		
		int a = divide(arr, w_left, w_mid,h_left,h_mid,length/2,isblue);
		int b = divide(arr, w_left, w_mid, h_mid + 1, h_right, length / 2,isblue);
		int c = divide(arr, w_mid+1, w_right,h_left,h_mid, length / 2,isblue);
		int d = divide(arr, w_mid+1, w_right, h_mid+1, h_right, length / 2,isblue);
		return a + b + c + d;
	}
	else
		return 0;
	

}


int main(void)
{
	
	int count;
	int whiteCount;
	int blueCount;
	
	cin >> count;
	int** N = new int* [count];
	
	for (int i = 0; i < count; i++)
	{
		N[i] = new int[count];
		for (int j = 0; j < count; j++)
		{
			cin >> N[i][j];
		}
	}
	

	
	blueCount = divide(N, 0, count - 1, 0, count - 1, count, true);
	whiteCount = divide(N, 0, count - 1, 0, count - 1, count, false);

	cout << whiteCount << endl;
	cout << blueCount << endl;
	
	return 0;

}