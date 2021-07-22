#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int count_max;
vector<pair<int, int>> virus;

void DFS(vector<vector<int>> lab)
{

    bool visited[9][9];
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) visited[i][j] = false;
    int count = 0;

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    vector<pair<int, int>> virus_re;
    //queue<pair<int, int>> virus_re;
    for (int i = 0; i < virus.size(); i++)
        virus_re.push_back({ virus[i].first,virus[i].second });
    //virus_re.push({ virus[i].first,virus[i].second });


    while (!virus_re.empty())
    {
        //int first = virus_re.front().first;
        //int second = virus_re.front().second;
        int first = virus_re.back().first;
        int second = virus_re.back().second;

        //virus_re.pop();
        virus_re.pop_back();

        for (int i = 0; i < 4; i++)
        {
            int next_first = first + dx[i];
            int next_second = second + dy[i];

            if (next_first < 0 || next_first >= n || next_second < 0 || next_second >= m)
                continue;

            if (lab[next_first][next_second] != 0 || visited[next_first][next_second] == true)
                continue;

            visited[next_first][next_second] = true;
            lab[next_first][next_second] = 2;
            //virus_re.push({ next_first,next_second });
            virus_re.push_back({ next_first,next_second });

        }


    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (lab[i][j] == 0)
                count++;
        }
    }

    if (count_max < count)
        count_max = count;

}

void search(vector<vector<int>> lab, int cnt)
{
    if (cnt == 3)
    {
        DFS(lab);
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (lab[i][j] == 0)
                {
                    lab[i][j] = 1;
                    cnt++;
                    search(lab, cnt);
                    cnt--;
                    lab[i][j] = 0;
                }
            }
        }
    }
}

int main() {

    vector<vector<int>> lab;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        vector<int> a;
        for (int j = 0; j < m; j++)
        {
            int b;
            cin >> b;
            a.push_back(b);
            if (b == 2)
                virus.push_back({ i,j });

        }
        lab.push_back(a);
        a.clear();
    }


    search(lab, 0);

    cout << count_max << endl;

    return 0;
}