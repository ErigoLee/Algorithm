#include <iostream>

using namespace std;
long long memo[1001][1001] = { 0 };
int main() {
    const int mod = 1000000007;


    int num, num2;
    //int answer;
    cin >> num >> num2;
    memo[1][1] = 1;

    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= num2; j++) {
            if (i * j > 1)
                memo[i][j] = ((memo[i - 1][j] % mod) + (memo[i][j - 1] % mod) + (memo[i - 1][j - 1] % mod)) % mod;
        }
    }

    cout << memo[num][num2] % mod << endl;

    return 0;
}