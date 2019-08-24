import sys
T= int(sys.stdin.readline())
direction = [[0,1],[1,0],[0,-1],[-1,0]]

def DFS(p):
    for dir in direction:
        np = [p[0] + dir[0], p[1] + dir[1]]
        if ( np[0] <= N-1 and np[0] >= 0) and (np[1] <= M-1 and np[1] >=0):
            if maps[np[0]][np[1]] == 1 and check[np[0]][np[1]] == False:
                check[np[0]][np[1]] = True
                DFS(np)
for i in range(T):
    N, M, K= map(int,sys.stdin.readline().split())
    maps = [[0 for _ in range(M)] for _ in range(N)]
    check = [[False for _ in range(M)] for _ in range(N)]
    point = []
    for i in range(K):
        x , y = map(int,sys.stdin.readline().split())
        maps[x][y] = 1
        #if i == 0: point = [x,y]
        point.append([x,y])
    cnt = 0
    que = [point[0]]
    for p in point:
        if check[p[0]][p[1]] == False:
            cnt +=1
            check[p[0]][p[1]] = True
            DFS(p)
    print(cnt)
