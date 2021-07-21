#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> depth_first_search(vector<vector<int>> graph, int start)
{
	stack<int> stack;
	vector<bool> visited(graph.size(), false);// 방문 여부
	vector<int> visited_order; //방문한 순서

	stack.push(start);
	

	while (!stack.empty())
	{
		int current_vertex = stack.top();
		stack.pop();
		
		if (!visited[current_vertex]) {

			visited_order.push_back(current_vertex);
			visited[current_vertex] = true;
			int size = graph[current_vertex].size();
			for (int i = size - 1; i > -1; --i) {
				int next_vertex = graph[current_vertex][i];
				stack.push(next_vertex);
			}
		}
		

	}

	return visited_order;
}

vector<int> breath_first_search(vector<vector<int>> graph, int start)
{
	queue<int> queue;
	vector<bool> visited(graph.size(), false);// 방문 여부
	vector<int> visited_order; //방문한 순서

	queue.push(start);
	while (!queue.empty())
	{
		int current_vertex = queue.front();
		queue.pop();

		if (!visited[current_vertex]) {
			visited_order.push_back(current_vertex);
			visited[current_vertex] = true;

			for (int i = 0; i < graph[current_vertex].size(); i++)
			{
				int next_vertex = graph[current_vertex][i];

				queue.push(next_vertex);

			}
		}
		

	}

	return visited_order;
}


int main()
{
	int V, E, start;
	cin >> V >> E >> start;

	vector<vector<int>> graph(V + 1);
	for (int i = 0; i < E; i++)
	{
		int src, dst;
		cin >> src >> dst;
		graph[src].push_back(dst);
		graph[dst].push_back(src);

	}

	for (int i = 0; i <= V; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	vector<int> depth_first_order = depth_first_search(graph,start);
	for (int i = 0; i < depth_first_order.size(); i++)
	{
		cout << depth_first_order[i] << " ";
	}
	cout << endl;

	vector<int> breath_first_order = breath_first_search(graph,start);
	for (int i = 0; i < breath_first_order.size(); i++)
	{
		cout << breath_first_order[i] << " ";
	}
	cout << endl;

	return 0;
}