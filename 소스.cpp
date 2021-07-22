#include <iostream>
#include <vector>
using namespace std;
int fibo[41][2];

void fibofun(int n)
{
    if (n == 0)
    {
        fibo[0][0] = 1;
        fibo[0][1] = 0;
        return;
    }

    if (n == 1)
    {
        fibo[1][0] = 0;
        fibo[1][1] = 1;
        return;
    }

    if (fibo[n][0] != 0 && fibo[n][1] != 0)
        return;

    if (fibo[n - 1][0] == 0 && fibo[n - 1][1] == 0)
        fibofun(n - 1);
    if (fibo[n - 2][0] == 0 && fibo[n - 2][1] == 0)
        fibofun(n - 2);

    fibo[n][0] = fibo[n - 1][0] + fibo[n - 2][0];
    fibo[n][1] = fibo[n - 1][1] + fibo[n - 2][1];
}


int main() {
    int T;
    vector<pair<int, int>> answer;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int num;
        cin >> num;
        fibofun(num);
        answer.push_back({ fibo[num][0],fibo[num][1] });
    }

    for (int i = 0; i < T; i++)
    {
        cout << answer[i].first << " " << answer[i].second << endl;
    }

}