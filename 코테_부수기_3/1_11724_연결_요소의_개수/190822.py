N, M= map(int,input().split())
maps =[[i] for i in range(1,N+1)]
connected = []
remain = [i for i in range(1,N+1)] #일단 처음에 확인해야 할 리스트

for i in range(M):
    u,v=map(int,input().split())
    maps[u-1].append(v)
    maps[v-1].append(u)

while remain != []: #모든 노드를 확인할때까지
    checklist=[remain[0]] #남은 노드 중 첫 노드를 확인 큐에 넣는다
    yoso = [] #노드에 연결된 얘들을 넣을 리스트
    #if checklist = [1,2]
    while checklist != []: #확인 큐가 빌때까지
        item = checklist.pop(0)  #1부터 시작해서
        #print(item,checklist,yoso)
        if item not in yoso: #지금 연결된 얘들리스트 = yoso에 있는지 확인하고
            yoso.append(item) #없으면 추가하고
            checklist.extend(maps[item-1]) #지금 연결된 얘들이랑 연결되어있으니 확인큐에 추가
    connected.append(yoso) #확인큐가 비었다는 거는 더 연결된 친구는 없다는 것으로 연결요소 묶음에 추가

    remain = [rest for rest in remain if rest not in yoso] #현재 연결된 멤버들을 확인 노드 리스트에서 제거
    #print(remain)
    #print(checklist,yoso)
print(len(connected))
