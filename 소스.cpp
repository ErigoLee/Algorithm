#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCheck(string p) {

    stack<char> temp;
    int length = p.length();

    for (int i = 0; i < length; i++) {
        if (p[i] == '(')
            temp.push(p[i]);
        else {
            if (temp.empty())
                return false;
            else {
                temp.pop();
            }
        }
    }
    return true;
}

string checking(string p) {
    if (p.compare("")==0)
        return "";
    int length = p.length();
    int cnt = 0;
    string u;
    string v;
    for (int i = 0; i < length; i++) {
        if (p[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt == 0) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            p = v;
            break;
        }
    }

    if(isCheck(u))
        return u + checking(p);
    else {
        string ret = "(" + checking(p) + ")";
        int length = u.length();
        for (int i = 1; i < length - 1; i++) {
            u[i] == '('? ret += ")" : ret += "(";
        }
        return ret;
    }
}



string solution(string p) {
    string answer = checking(p);
    cout << answer << endl;
    return answer;
}

int main() {
    //"(()())()"
    //"()))((()"
    string p = "()))((()";
    solution(p);
    return 0;
}