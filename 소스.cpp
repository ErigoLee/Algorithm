#include <iostream>
using namespace std;
int stickers[2][100001];
int dp[2][100001];


int MAX(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int main() {

    int sticker_case;
    int sum;

    cin >> sticker_case;

    for (int i = 0; i < sticker_case; i++)
    {

        int N;
        cin >> N;

        for (int j = 0; j < 2; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                int a;
                cin >> a;
                stickers[j][k] = a;
            }
        }
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[0][1] = stickers[0][1];
        dp[1][1] = stickers[1][1];


        for (int j = 2; j <= N; j++)
        {

            dp[0][j] = MAX(dp[1][j - 1], dp[0][j - 2]) + stickers[0][j];
            dp[0][j] = MAX(dp[0][j], dp[1][j - 2] + stickers[0][j]);

            dp[1][j] = MAX(dp[0][j - 1], dp[0][j - 2]) + stickers[1][j];
            dp[1][j] = MAX(dp[1][j], dp[1][j - 2] + stickers[1][j]);

        }

        if (dp[0][N] >= dp[1][N])
            sum = dp[0][N];
        else
            sum = dp[1][N];

        cout << sum << endl;
        sum = 0;
        for (int j = 1; j <= N; j++) dp[1][j] = dp[0][j] = 0;

    }

    return 0;
}