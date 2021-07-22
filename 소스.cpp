#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos
{
    int x;
    int y;
};

int main() {
    int test_case, count = 1;
    vector<int> results;
    cin >> test_case;

    while (test_case != 0)
    {
        int n = test_case;
        int cave[125][125], obstacles[125][125];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> cave[i][j];
                obstacles[i][j] = 999999;
            }
        }
        obstacles[0][0] = cave[0][0];

        int rx[4] = { 1, 0, -1, 0 };
        int ry[4] = { 0, 1, 0, -1 };

        queue <Pos> q;
        Pos a = { 0, 0 };
        q.push(a);
        while (!q.empty())
        {
            Pos npos = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = npos.x + rx[i];
                int ny = npos.y + ry[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if (obstacles[nx][ny] > obstacles[npos.x][npos.y] + cave[nx][ny])
                {
                    obstacles[nx][ny] = obstacles[npos.x][npos.y] + cave[nx][ny];
                    Pos nnpos = { nx, ny };
                    q.push(nnpos);
                }

            }
        }
        results.push_back(obstacles[n - 1][n - 1]);

        cin >> test_case;
    }

    int size = results.size();

    for (int i = 0; i < size; i++)
    {
        cout << "Problem " << i + 1 << ": " << results[i] << endl;
    }


    return 0;
}