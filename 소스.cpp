#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visited[50][50];


int main() {

    vector<vector<int>> route;
    int d_x[4] = { 0,-1,0,1 };
    int d_y[4] = { -1,0,1,0 };
    int back_x[4] = { 1,0,-1,0 };
    int back_y[4] = { 0,-1,0,1 };
    int n, m;
    int x, y, direction;
    int result = 0;

    cin >> n >> m;
    cin >> x >> y >> direction;

    for (int i = 0; i < n; i++)
    {
        vector<int> a;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        route.push_back(a);
        a.clear();
    }


    queue<pair<int, int>> qu;
    qu.push({ x,y });
    visited[x][y] = true;
    result++;
    while (!qu.empty())
    {
        int node_x = qu.front().first;
        int node_y = qu.front().second;
        qu.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = node_x + d_x[direction];
            int next_y = node_y + d_y[direction];

            if (route[next_x][next_y] == 0 && visited[next_x][next_y] == false)
            {
                visited[next_x][next_y] = true;
                result++;
                qu.push({ next_x,next_y });
                direction = direction - 1;
                if (direction == -1)
                    direction = 3;
                break;
            }

            direction = direction - 1;
            if (direction == -1)
                direction = 3;
        }

        if (qu.empty())
        {
            int next_x = node_x + back_x[direction];
            int next_y = node_y + back_y[direction];
            if (route[next_x][next_y] == 0)
                qu.push({ next_x,next_y });
        }

    }


    cout << result << endl;

    return 0;
}