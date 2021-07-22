#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 10000
#define INF 2100000000
int costs[MAX + 1];
using namespace std;
void func(int start, vector<pair<int, int>> node[MAX + 1]) {

    for (int i = 0; i < MAX + 1; i++)
        costs[i] = INF;
    queue<pair<int, int>>qu;
    pair<int, int> p = make_pair(start, 0);
    costs[start] = 0;
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
}


int main() {
    int incident;
    vector <pair<int, int>> incidents;
    vector <pair<int, int>> comp[MAX + 1];
    cin >> incident;

    for (int i = 0; i < incident; i++) {
        int comp_count, line, hacking;
        cin >> comp_count >> line >> hacking;
        for (int j = 0; j < line; j++) {
            int node_1, node_2, time;
            cin >> node_1 >> node_2 >> time;
            pair<int, int> p = make_pair(node_1, time);
            comp[node_2].push_back(p);
        }
        func(hacking, comp);
        int count = 0, max = 0;
        for (int j = 1; j <= comp_count; j++) {
            if (costs[j] < INF) {
                count++;
                if (max < costs[j]) max = costs[j];
            }
        }
        pair<int, int> p2 = make_pair(count, max);
        incidents.push_back(p2);
        for (int j = 1; j <= comp_count; j++) comp[j].clear();
    }

    int size = incidents.size();
    for (int i = 0; i < size; i++) {
        cout << incidents[i].first << " " << incidents[i].second << endl;
    }

    return 0;
}