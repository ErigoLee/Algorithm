#include <iostream>
#include <string>

using namespace std;
string answer = "";
int num;
bool func2(string check_str)
{
    if (check_str.size() == 1)
        return true;
    int length = check_str.length();

    for (int i = 1; i <= length / 2; i++)
    {
        for (int j = 0; j < length - i; j++)
        {
            if (check_str.substr(j, i) == check_str.substr(j + i, i))
                return false;
        }
    }

    return true;
}

void func1(string check, int cnt)
{
    if (num == cnt)
    {
        answer = check;
        cout << answer;
        exit(0);
        return;
    }

    string checked_str = "";
    for (int i = 1; i <= 3; i++)
    {
        checked_str = check + to_string(i);

        if (func2(checked_str)) {
            func1(checked_str, cnt + 1);
        }
    }

}



int main() {


    cin >> num;

    func1("", 0);


    return 0;
}