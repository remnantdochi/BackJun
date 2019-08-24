import sys

N = int(sys.stdin.readline())
L = int(sys.stdin.readline())

check = [0]*(N+1) #확인 결과

maps = [[] for i in range(N+1)]
for i in range(L):
    u,v = map(int,sys.stdin.readline().split())
    maps[u].append(v)
    maps[v].append(u)

cnt =0
que =maps[1]
check[1] = 1
while que != []:
    item = que.pop(0)
    if  check[item] == 0:
        check[item] =1
        cnt+=1
        que.extend(maps[item])

print(cnt)
