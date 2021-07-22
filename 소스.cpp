#include <iostream>
#include <vector>

using namespace std;

int main() {
    int count;
    int memo[11];
    vector<int> T;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int num;
        cin >> num;
        T.push_back(num);
    }

    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for (int i = 4; i < 11; i++)
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];

    for (size_t i = 0; i < count; i++) {
        cout << memo[T[i]] << endl;
    }


    return 0;
}