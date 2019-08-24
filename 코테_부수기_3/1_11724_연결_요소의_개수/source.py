import sys
sys.setrecursionlimit(10000)
N, M= map(int,input().split())
maps =[[] for i in range(N+1)]
remain = [False]*(N+1) #일단 처음에 확인해야 할 리스트

for i in range(M):
    u,v=map(int,input().split())
    maps[u-1].append(v)
    maps[v-1].append(u)
#print(maps)
cnt=0
def checking(node):
    remain[node] = True
    for item in maps[node]:
        if remain[item] == False:
            checking(item)

for i in range(1,N+1):
    if remain[i] == False:
        cnt+=1
        checking(i)
print(cnt)
