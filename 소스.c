#include <stdio.h>
#include <math.h>

int count_function(int N, int r, int c) {

	int count = 0; //횟수 세기
	if (N == 1) {
		if (r == 0 && c == 0) {
			return count;
		}
		else
			count++;
		if (r == 0 && c == 1) {
			return count;
		}
		else
			count++;
		if (r == 1 && c == 0) {
			return count;
		}
		else
			count++;
		if (r == 1 && c == 1) {
			return count;
		}
		else
			count++;
	}
	else {
		int index_N = N - 1;
		int index = (int)pow(2, index_N);
		if (r < index && c < index) {
			return count_function(N - 1, r, c);
		}
		else if (r < index && c >= index)
			return index * index + count_function(N - 1, r, c - index);
		else if (r >= index && c < index)
			return 2 * index * index + count_function(N - 1, r - index, c);
		else
			return 3 * index * index + count_function(N - 1, r - index, c - index);
	}

}

int main(int argc, char** argv) {

	int N; // 2^N에서의 N의 import 값 저장할 변수
	long int index; // 2^N의 value 저장할 변수
	int r; //(r,c)에서 r value 저장할 변수
	int c; //(r,c)에서 s value 저장할 변수


	while (1) {
		scanf("%d", &N);
		index = pow(2, N);
		scanf("%d", &r);
		scanf("%d", &c);

		if (1 <= N && N <= 15)
			if (0 <= r && r <= index - 1)
				if (0 <= c && c <= index - 1)
					break;
	}
	int count = count_function(N, r, c);
	printf("%d", count);

	return 0;
}