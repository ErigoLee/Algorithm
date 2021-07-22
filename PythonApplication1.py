##main value
graph=list()
N=0 ##first
M=0 ##second
##dx[0],dy[0] =>오른쪽
##dx[1],dy[1] =>왼쪽
##dx[2],dy[2] =>아래
##dx[3],dy[3] =>위

dx = [0,0,1,-1]
dy = [1,-1,0,0]

## bfs function
def bfs(start_node_1,start_node_2):
    visit = list()##방문한 노드
    queue = list()##BFS로 사용할 큐
    distance = [[0 for _ in range(M)] for _ in range(N)]
    distance[0][0] = 1

    queue.append([start_node_1,start_node_2])
    while queue:
        [start_node_1,start_node_2]=queue.pop(0)
        if [start_node_1,start_node_2] is not visit:
            visit.append([start_node_1,start_node_2])
            for i in range(4):
                node_1 = start_node_1+dx[i]
                node_2 = start_node_2+dy[i]
                if node_1>=0 and node_1<N and node_2>=0 and node_2<M and graph[node_1][node_2]==1:
                    if [node_1,node_2] not in visit and [node_1,node_2] not in queue:
                        queue.append([node_1,node_2])
                        distance[node_1][node_2] = distance[start_node_1][start_node_2]+1
    return distance[N-1][M-1]


##main input
while True:
    N, M = map(int, input().split())
    if 2<=N and N<=100 and 2<=M and M<=100:
        break

for i in range(N):
    graph.append(list(map(int, str(input()))))

visit = bfs(0,0)
print(visit)
