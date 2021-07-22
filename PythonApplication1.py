##value
graph = list()
##dx[0],dy[0] =>오른쪽
##dx[1],dy[1] =>왼쪽
##dx[2],dy[2] =>아래
##dx[3],dy[3] =>위

dx = [0,0,1,-1]
dy = [1,-1,0,0]
visit = list()
count = 0
##function
def bfs(start_node1,start_node2):
    global count
    count = count + 1
    count_2 = 0
    queue = list()
    queue.append([start_node1,start_node2])
    while queue:
        [start_node1,start_node2] = queue.pop(0)

        if graph[start_node1][start_node2] != 1:
            continue
        visit.append([start_node1, start_node2])
        count_2 = count_2 + 1
        distance[start_node1][start_node2] = count
        for i in range(4):
            node_1 = start_node1+dx[i]
            node_2 = start_node2+dy[i]
            if node_1 >= 0 and node_1 < N and node_2 >= 0 and node_2<N:
                if [node_1,node_2] not in visit and [node_1,node_2] not in queue:
                    queue.append([node_1,node_2])
    return count_2

##main input
while True:
    N = int(input())
    if 5<=N and N<=25:
        break

for i in range(N):
    graph.append(list(map(int, str(input()))))
##print(graph)
T = list()
distance = [[0 for _ in range(N)] for _ in range(N)]
for i in range (0,N,1):
    for j in range (0,N,1):
        if graph[i][j] == 1 and [i,j] not in visit:
            temp = bfs(i,j)
            T.append(temp)
print(len(T))
T.sort()
for i in T:
    print(i)
