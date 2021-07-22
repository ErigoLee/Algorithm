#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 1000
#define INF 2100000000

using namespace std;
int func(int start, int end, vector<pair<int, int>> node[MAX + 1]) {

    int costs[MAX + 1];
    if (start == end) return 0;

    for (int i = 0; i < MAX + 1; i++)
        costs[i] = INF;
    queue<pair<int, int>>qu;
    pair<int, int> p = make_pair(start, 0);
    qu.push(p);


    while (!qu.empty()) {
        int route_start = qu.front().first;
        int cost = qu.front().second;

        qu.pop();
        int size = node[route_start].size();
        for (int i = 0; i < size; i++) {
            int next_route_start = node[route_start][i].first;
            int next_cost = node[route_start][i].second + cost;
            if (costs[next_route_start] > next_cost) {
                costs[next_route_start] = next_cost;
                pair<int, int>p2 = make_pair(next_route_start, next_cost);
                qu.push(p2);
            }

        }

    }

    return costs[end];
}


int main() {
    vector<pair<int, int>> node[MAX + 1];
    int count[MAX + 1];
    int N, M, X;
    int max = 0;
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int num, num2, num3;
        cin >> num >> num2 >> num3;
        pair<int, int> p = make_pair(num2, num3);
        node[num].push_back(p);
    }

    for (int i = 1; i <= N; i++) {
        count[i] = func(i, X, node) + func(X, i, node);
    }
    for (int i = 1; i <= N; i++) {
        if (max < count[i] && count[i] < INF) {
            max = count[i];
        }
    }

    cout << max << endl;


    return 0;
}