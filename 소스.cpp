#include <iostream>

using namespace std;
int main() {
    long long fibo[91];
    int number;
    cin >> number;

    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= number; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    cout << fibo[number] << endl;
    return 0;
}