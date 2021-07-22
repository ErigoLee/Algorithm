#include <stdio.h>
#include <stdlib.h>
const int mod = 1e9 + 7;
long long int memo[1001][1001] = { 0 };
int main() {

    int num, num2;
    scanf("%d", &num);
    scanf("%d", &num2);

    memo[1][1] = 1;

    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= num2; j++) {
            if (i * j > 1)
                memo[i][j] = ((memo[i - 1][j] % mod) + (memo[i][j - 1] % mod) + (memo[i - 1][j - 1] % mod)) % mod;
        }
    }


    printf("%lld\n", memo[num][num2] % mod);
    return 0;
}