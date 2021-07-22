#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MaxN 20000

using namespace std;
int node_route[MaxN + 1];
bool visited[MaxN + 1];


int main() {

    int n, m; //n: 노드 수, m: 엣지 수
    int result_node = 0, distance = 0, same_count = 0;


    cin >> n >> m;
    vector<int> route[MaxN + 1];
    //각 노드별 연결 되는 노드를 push함
    for (int i = 0; i < m; i++) {
        int a[2];
        for (int j = 0; j < 2; j++)
            cin >> a[j];

        route[a[0]].push_back(a[1]);
        route[a[1]].push_back(a[0]);
    }

    for (int i = 1; i <= n; i++) visited[i] = false;

    queue<pair<int, int> >qu;

    pair<int, int> p = make_pair(0, 1);
    qu.push(p);
    visited[1] = true;
    node_route[1] = 0;

    while (!qu.empty()) {
        int dist = qu.front().first;
        int here = qu.front().second;

        qu.pop();
        int rsize = route[here].size();
        for (int i = 0; i < rsize; i++) {
            int next = route[here][i];
            if (visited[next] == false) {
                node_route[next] = dist + 1;
                pair<int, int> p2 = make_pair(node_route[next], next);
                qu.push(p2);
                visited[next] = true;
            }
        }

    }


    for (int i = 1; i <= n; i++) {
        if (distance < node_route[i]) {
            distance = node_route[i];
            same_count = 0;
            result_node = i;
        }
        if (distance == node_route[i])
            same_count++;
    }

    cout << result_node << " " << distance << " " << same_count << endl;

    return 0;
}