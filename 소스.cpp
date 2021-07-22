#include <iostream>
#include <vector>
#include <queue>

#define INF 999999999;

using namespace std;

int dijkstra(int n, vector<vector<int>> test_case)
{
    queue<pair<int, int>> qu;
    int shortest[125][125];
    int cal[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) shortest[i][j] = INF;

    shortest[0][0] = test_case[0][0];

    pair<int, int> p = make_pair(0, 0);
    qu.push(p);

    while (!qu.empty())
    {
        int first = qu.front().first;
        int second = qu.front().second;

        qu.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_first = first + cal[i][0];
            int next_second = second + cal[i][1];
            if ((next_first >= 0 && next_first < n) && (next_second >= 0 && next_second < n))
            {
                if (shortest[next_first][next_second] > shortest[first][second] + test_case[next_first][next_second])
                {
                    shortest[next_first][next_second] = shortest[first][second] + test_case[next_first][next_second];
                    pair<int, int> next = make_pair(next_first, next_second);
                    qu.push(next);
                }
            }
        }
    }

    int answer = shortest[n - 1][n - 1];
    return answer;
}



int main() {

    int count;
    vector<vector<int>> test_case;
    vector<int> result;

    while (true)
    {
        cin >> count;
        if (count <= 0)
            break;

        for (int i = 0; i < count; i++)
        {
            vector<int> a;
            for (int j = 0; j < count; j++)
            {
                int b;
                cin >> b;
                a.push_back(b);
            }
            test_case.push_back(a);

            while (!a.empty()) a.pop_back();
        }

        int res = dijkstra(count, test_case);
        result.push_back(res);
        while (!test_case.empty()) test_case.pop_back();
    }

    int size = result.size();

    for (int i = 0; i < size; i++)
    {
        cout << "Problem " << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}