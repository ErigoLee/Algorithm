#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define N 100
#define M 100000000
//int space[N][N];
//int space2[N][N];
int visited[N][N];
int visited2[N][N];
using namespace std;

void func(int x, int y, bool check, int count, int num, vector<string> Value) {

    queue<pair<int, int>> qu;
    pair<int, int> p = make_pair(x, y);
    qu.push(p);
    visited[x][y] = true;
    //space[x][y] = count;

    while (!qu.empty()) {
        int first = qu.front().first;
        int second = qu.front().second;
        qu.pop();
        int next_1, next_2;
        bool check2 = false;
        for (int i = 0; i < 4; i++) {

            switch (i) {
            case 0:
                if (first - 1 >= 0) {
                    next_1 = first - 1;
                    next_2 = second;
                    check2 = true;
                }
                break;
            case 1:
                if (second - 1 >= 0) {
                    next_1 = first;
                    next_2 = second - 1;
                    check2 = true;
                }
                break;
            case 2:
                if (first + 1 < num) {
                    next_1 = first + 1;
                    next_2 = second;
                    check2 = true;

                }
                break;
            case 3:
                if (second + 1 < num) {
                    next_1 = first;
                    next_2 = second + 1;
                    check2 = true;
                }
                break;
            }
            if (check2 == true && check == true) {
                if (Value[next_1][next_2] == Value[first][second] && visited[next_1][next_2] == false) {
                    visited[next_1][next_2] = true;
                    //space[next_1][next_2] = count;
                    pair<int, int> p2 = make_pair(next_1, next_2);
                    qu.push(p2);
                }
                check2 = false;
            }
            else if (check2 == true && check == false) {
                if (Value[next_1][next_2] == Value[first][second] && visited2[next_1][next_2] == false) {
                    visited2[next_1][next_2] = true;
                    //space2[next_1][next_2] = count;
                    pair<int, int> p2 = make_pair(next_1, next_2);
                    qu.push(p2);
                }
                else {
                    if ((Value[next_1][next_2] == 'G' && Value[first][second] == 'R') || (Value[next_1][next_2] == 'R' && Value[first][second] == 'G')) {
                        if (visited2[next_1][next_2] == false) {
                            visited2[next_1][next_2] = true;
                            //space2[next_1][next_2] = count;
                            pair<int, int> p2 = make_pair(next_1, next_2);
                            qu.push(p2);
                        }
                    }
                }
                check2 = false;
            }
            else
                continue;
        }
    }
}

int main() {
    int num;
    vector<string> Value;
    cin >> num;
    for (int i = 0; i < num; i++) {
        string grap;
        cin >> grap;
        Value.push_back(grap);
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            visited[i][j] = false;
            visited2[i][j] = false;
            //space[i][j] = M;
            //space2[i][j] = M;
        }
    }

    int num2 = 1;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (visited[i][j] == false) {
                func(i, j, true, num2, num, Value);
                num2++;
            }
        }
    }
    int num3 = 1;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (visited2[i][j] == false) {
                func(i, j, false, num3, num, Value);
                num3++;
            }
        }
    }
    /*
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << space[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << space2[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << --num2 << " " << --num3 << endl;

    return 0;
}