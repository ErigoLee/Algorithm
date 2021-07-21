#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int depth_first_search(vector<vector<int>>graph, int start)
{
	stack<int> stack;
	vector<bool> visited(graph.size(),false);
	vector<int> visited_order;

	stack.push(start);

	while (!stack.empty())
	{
		int current_vertex = stack.top();
		stack.pop();
		if (!visited[current_vertex]) {
			visited[current_vertex] = true;
			visited_order.push_back(current_vertex);
			int size = graph[current_vertex].size();
			for (int i = size - 1; i > -1; --i) {
				int next_vertex = graph[current_vertex][i];
				stack.push(next_vertex);
			}
		}
	}

	return visited_order.size();

}

int main()
{
	int V, E;
	cin >> V;
	cin >> E;

	vector<vector<int>> graph(V + 1);

	for (int i = 0; i < E; i++)
	{
		int src, dst;
		cin >> src >> dst;
		graph[src].push_back(dst);
		graph[dst].push_back(src);
	}

	for (int i = 1; i <= V; i++) {
		sort(graph[i].begin(),graph[i].end());
	}

	
	int result = depth_first_search(graph,1);

	cout << result-1 << endl;
	return 0;
}