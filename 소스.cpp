#include <iostream>

using namespace std;
int fibo[21];

int fibofun(int num) {
    if (fibo[num]) {
        return fibo[num];
    }

    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else {
        int a = fibofun(num - 1) + fibofun(num - 2);
        fibo[num] = a;
        return fibo[num];
    }
}



int main() {

    int num;
    cin >> num;

    int answer = fibofun(num);

    cout << answer << endl;

    return 0;
}