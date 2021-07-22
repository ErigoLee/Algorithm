#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;
int main() {

    stack<string> string_stack;
    queue<string> array_strings;
    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string a;
        cin >> a;
        array_strings.push(a);
    }

    for (int i = 0; i < count; i++)
    {
        string b = array_strings.front();
        array_strings.pop();
        int length = b.length();
        bool check = true;

        for (int j = 0; j < length; j++)
        {
            if (b[j] == '(')
                string_stack.push("(");

            if (b[j] == ')')
            {
                if (string_stack.empty()) {
                    check = false;
                    break;
                }
                string_stack.pop();
            }
        }
        if (!string_stack.empty() && check == true)
            check = false;

        if (!string_stack.empty())
        {
            while (!string_stack.empty())
                string_stack.pop();
        }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}