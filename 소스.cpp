#include <iostream>
using namespace std;
int storage[501][20]; // 메모화 재귀 표현
int title(int N, int bits)
{
    int result = 0;
    if (N <= 0) return 0;
    if (N == 1 && bits == 6) return 0;
    if (N == 1) return 1;
    if (storage[N][bits]) return storage[N][bits];

    switch (bits)
    {
    case 0:
        result = title(N - 1, 0) + title(N - 1, 3) + title(N - 1, 9) + title(N - 1, 12) + title(N - 1, 15);
        break;
    case 3:
        result = title(N - 1, 0) + title(N - 1, 12);
        break;
    case 6:
        result = title(N - 1, 9);
        break;
    case 9:
        result = title(N - 1, 0) + title(N - 1, 6);
        break;
    case 12:
        result = title(N - 1, 0) + title(N - 1, 3);
        break;
    case 15:
        result = title(N - 1, 0);
        break;
    }
    storage[N][bits] = result;
    return result;
}


int main() {

    int testcase;
    cin >> testcase;

    int results[1001];

    for (int i = 0; i < testcase; i++)
    {
        int N;
        cin >> N;
        results[i] = title(N, 0);
    }

    for (int i = 0; i < testcase; i++)
    {
        cout << results[i] << endl;
    }

    return 0;
}