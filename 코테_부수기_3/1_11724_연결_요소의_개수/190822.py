N, M= map(int,input().split())
maps =[[i] for i in range(1,N+1)]
connected = []
remain = [i for i in range(1,N+1)]
# if M == 0:
#     print(N)
#     return

for i in range(M):
    u,v=map(int,input().split())
    maps[u-1].append(v)
    maps[v-1].append(u)

while remain != []:
    checklist=[remain[0]]
    yoso = []

    while checklist != []:
        item = checklist.pop(0)
        #print(item,checklist,yoso)
        if item not in yoso:
            yoso.append(item)
            checklist.extend(maps[item-1])
    connected.append(yoso)

    remain = [rest for rest in remain if rest not in yoso]
    #print(remain)
    #print(checklist,yoso)
print(len(connected))
