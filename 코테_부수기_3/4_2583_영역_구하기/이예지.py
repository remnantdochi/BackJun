import sys
M, N, K = map(int,sys.stdin.readline().split())
maps = [[0 for _ in range(N)] for _ in range(M)]
#remain = [[False for _ in range(N)] for _ in range(M)]
for _ in range(K):
    e1, s1, e2, s2 = map(int, sys.stdin.readline().split())
    for i in range(s1,s2):
        maps[i][e1:e2] = [1 for _ in range(e2-e1)]
        #remain[i][e1:e2] = [-1 for _ in range(e2-e1)]
#print(maps)
directions = [[0,1],[1,0],[0,-1],[-1,0]]

def sol(i,j):
    checkque = [[i,j]]
    maps[i][j] = 1
    #remain[i][j] = True
    s = 1
    while checkque:
        np = checkque.pop(0)
        nx, ny = np[0], np[1]
        for dir in directions:
            x = dir[0] + nx
            y = dir[1] + ny
            if (0<= x < M and 0 <= y < N):
                if maps[x][y] == 0:
                    maps[x][y] = 1
                    s +=1
                    checkque.append([x,y])
        #print(checkque)
    return s
cnt = 0
ans = []

for i in range(M):
    for j in range(N):
        if maps[i][j] == 0:
            cnt +=1
            ans.append(sol(i,j))
print(cnt)
ans.sort()
for a in ans:
    print(a, end= " ")
