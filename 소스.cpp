#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> graph, vector<int> cost) {
    cost[start] = 0;
    queue<pair<int, int>> node;
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i].first;
        int nextcost = graph[start][i].second;
        node.push(make_pair(next, nextcost));
    }

    while (!node.empty()) {
        int next = node.front().first;
        int nextcost = node.front().second;

        node.pop();
        if (cost[next] > nextcost) {
            cost[next] = nextcost;
            for (int i = 0; i < graph[next].size(); i++) {
                node.push(make_pair(graph[next][i].first, graph[next][i].second + nextcost));
            }
        }
    }

    return cost;

}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> cost;
    vector<int> costA;
    vector<int> costB;
    for (int i = 0; i < fares.size(); i++) {
        int a = fares[i][0];
        int b = fares[i][1];
        int c = fares[i][2];
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    for (int i = 0; i <= n; i++) {
        cost.push_back(INF);
        costA.push_back(INF);
        costB.push_back(INF);
    }

    cost = dijkstra(s, graph,cost);
    costA = dijkstra(a,graph,costA);
    costB = dijkstra(b,graph,costB);

    for (int i = 1; i <= n; i++) {
        if (answer > cost[i] + costA[i] + costB[i])
            answer = cost[i] + costA[i] + costB[i];
    }

    return answer;
}

int main() {
    int answer;
    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;
    //[[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]
    int fares_array[][3] = { {4, 1, 10 }, { 3, 5, 24 }, { 5, 6, 2 }, { 3, 1, 41 }, { 5, 1, 24 }, { 4, 6, 50 }, { 2, 4, 66 }, { 2, 3, 22 }, { 1, 6, 25 } };
    vector<vector<int>> fares;
    for (int i = 0; i < 9; i++) {
        vector<int> temp;
        temp.push_back(fares_array[i][0]);
        temp.push_back(fares_array[i][1]);
        temp.push_back(fares_array[i][2]);
        fares.push_back(temp);
        temp.clear();
    }

    answer = solution(n, s, a, b, fares);
    cout << answer << endl;
    return 0;
}