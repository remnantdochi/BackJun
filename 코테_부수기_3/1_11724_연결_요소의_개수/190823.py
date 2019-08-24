N, M= map(int,input().split())
maps =[[] for i in range(1,N+1)]
remain = [False]*N #일단 처음에 확인해야 할 리스트

for i in range(M):
    u,v=map(int,input().split())
    maps[u-1].append(v)
    maps[v-1].append(u)
#print(maps)
cnt=0
for i in range(N):
    if remain[i] == False:
        cnt +=1
        remain[i] = True
        check = maps[i]
        #print('t1',check)
        while check != []:
            item = check.pop(0)
            #print('t2',item)
            if remain[item-1] == False:
                remain[item-1] = True
                #print('t3',remain)
                for a in maps[item-1]:
                    if remain[a-1] == False and a not in check:
                        #print('t4',a)
                        check.append(a)
                        #print('t5',check)

print(cnt)
