# Algorithm
백준, 프로그래머스 등등 문제 풀이        
백준 https://www.acmicpc.net/problem/16234  
16234번 문제입니다.      
틀린 코드 부분에서 알 수 있다시피    
저는 이 부분에서 틀렸다고 생각합니다.      
<pre>
<code>
if (tryagain) {
				count++;
				tryagain = false;
				k = -1;
				int totalSize = totalMove.size();
				for (int i = 0; i < totalSize; i++) {
					int size = totalMove[i].size();
					int total = 0;
					for (int j = 0; j < size; j++) {
						int x = totalMove[i][j].first;
						int y = totalMove[i][j].second;
						total += _graph[x][y];
					}
					int value = total / size;
					for (int j = 0; j < size; j++) {
						int x = totalMove[i][j].first;
						int y = totalMove[i][j].second;
						_graph[x][y] = value;
					}

				}
			}
</code>
</pre>
그 이유는 전체적으로 인구이동하는 코드를 작성하게 되면           
1회 인구 이동 시 2번 이상의 인구 변동이 발생할 수 있게 됩니다.    
즉, 1회 인구 이동 시 인구 이동이 한 번만 일어나야 되는 데 여러 번 일어나는 경우가 발생하게 됩니다.    
이와 같은 상황을 막고자, (다른 사람들의 코드를 좀 참고 했지만)     
visited변수를 사용해서, 2번 이상의 방문을 막고자 했습니다.       
이와 같은 형식으로      
<pre>
<code>
if (visited[next_x][next_y] == false) {
							pair<int, int> _next = make_pair(next_x, next_y);
							movesIndex.push_back(_next);
							_queue.push(_next);
							visited[next_x][next_y] = true;
}
</pre>
</code>
작성하면 정답이 나오게 됩니다.       
