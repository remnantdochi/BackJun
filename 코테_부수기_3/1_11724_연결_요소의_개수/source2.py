import sys
sys.setrecursionlimit(10000)
def dfs(i, G, V, N):
    V[i] = True
    for j in range(1, N+1):
        if V[j] == True or G[i][j] == 0:
            continue
        dfs(j, G, V, N)


def _11724():
    N = 1001
    graph = [[0] * N for i in range(N)]
    visited = [0] * N

    U, V = map(int,input().split(' '))
    for i in range(V):
        u, v = map(int, sys.stdin.readline().split())

        graph[u][v] = 1
        graph[v][u] = 1

    count = 0
    for i in range (1, U+1):
        if visited[i] == 0:
            dfs(i, graph, visited, U)
            count += 1

    print(count)
_11724()
