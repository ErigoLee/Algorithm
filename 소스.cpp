#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#define INF 2100000000

using namespace std;


vector<int> dijkstra(int start,vector<vector<pair<int,int>>> graph,int V)
{
	priority_queue<pair<int, int>> p;
	vector<int> cost(V+1,INF);

	
	p.push(make_pair(0,start));
	while (!p.empty()) {
		int distance = -p.top().first;
		int  curVertex= p.top().second;
		

		p.pop();
		if (cost[curVertex] < distance)
			continue;

		
		for (int i = 0; i < graph[curVertex].size(); i++) {
			int nextVertex = graph[curVertex][i].first;
			int nextdistance = graph[curVertex][i].second+distance;
			if (cost[nextVertex] > nextdistance) {
				cost[nextVertex] = nextdistance;
				pair<int, int> next = make_pair(-nextdistance,nextVertex);
				p.push(next);
			}

		}

	}
	return cost;
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E; //정점 수
	int startNode; //시작노드
	cin >> V >> E;
	cin >> startNode;
	

	vector<vector<pair<int, int>>> graph(V+1); //dst, weight
	
	for (int i = 0; i < E; i++)
	{
		
		int src, dst, weight;
		cin >> src>> dst>> weight;
		pair<int, int> new_graph = make_pair(dst,weight);
		graph[src].push_back(new_graph);
	}
	

	vector<int> distance = dijkstra(startNode, graph, V);
	distance[startNode] = 0;
	for (int i = 1; i <= V; i++) {
		if (distance[i] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << distance[i] << endl;
		}
		
	}

}