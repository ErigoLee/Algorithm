#include <iostream>
#include <queue>
#include <vector>
#define N 100001
#define INF 1000000007;

using namespace std;
vector<pair<int, int>> tree[N];

long long result;
long long dep(int here, int before)
{
    int size = tree[here].size();
    long long sum = 1;
    for (int i = 0; i < size; i++)
    {
        int next_node = tree[here][i].first;
        int next_weight = tree[here][i].second;
        if (next_node != before)
        {
            long long check = dep(next_node, here) * next_weight % INF;
            result = (result + check * sum) % INF;
            sum = (sum + check) % INF;
        }
    }
    return sum;
}


int main() {

    int node_count;
    long long sum = 0;
    cin >> node_count;
    int a[N];
    for (int i = 0; i < node_count - 1; i++)
    {
        int node_1, node_2, weight;
        cin >> node_1 >> node_2 >> weight;

        tree[node_1].push_back({ node_2,weight });
        tree[node_2].push_back({ node_1,weight });
        a[node_1]++;
        a[node_2]++;
    }



    sum = dep(1, 0);

    cout << result << endl;

    return 0;
}