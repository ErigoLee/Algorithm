#include <iostream>

using namespace std;

int title[1001];
static int divide_num = 10007;

int titling(int num)
{
    if (title[num])
        return title[num];

    if (num == 1)
        return 1;
    else if (num == 2)
        return 2;
    else {
        int a = titling(num - 1) + titling(num - 2);
        title[num] = a % divide_num;
        return title[num];
    }

}


int main() {


    int num;

    cin >> num;

    int answer = titling(num);
    cout << answer << endl;

    return 0;
}