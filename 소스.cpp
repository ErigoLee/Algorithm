#include <iostream>
using namespace std;

long long progress[101];
long long results[101];


long long counting(int n)
{
    if (progress[n])
        return progress[n];

    if (n == 1 || n == 2 || n == 3)
    {
        progress[n] = 1;
        return progress[n];
    }

    if (!progress[n - 3])
        progress[n - 3] = counting(n - 3);

    if (!progress[n - 2])
        progress[n - 2] = counting(n - 2);

    progress[n] = progress[n - 3] + progress[n - 2];

    return progress[n];
}

int main() {

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        int n;
        cin >> n;
        results[i] = counting(n);
    }

    for (int i = 0; i < test_case; i++)
        cout << results[i] << endl;
    return 0;
}