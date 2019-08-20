N, K = map(int, input().split())
medals = [[0]*4]*N
#global orders
orders = [0]*N

for i in range(N):
    medals[i] = list(map(int,input().split()))
temp = list(zip(*medals))

check = [temp[1],temp[0]]
medalorder = list(zip(*check))
medalorder.sort(reverse = True)
medalcolor = 1
#젤 처음 시작 group, groupnumber
# group : [1,'''.N] = temp[0] groupnumber : N
def makingorder(groupnumber,group,medalcolor):
        # 다시 정렬해줘야 하나...?
    check = [temp[medalcolor],temp[0]]
    checklist = list(zip(*check))
    checklist.sort(reverse = True)
    point = checklist[0][0]
    print('checklist',checklist)
    score = 0
    samenum = 0
    nextgroup = []
    nextgroupnum = 0
    print('currentgroup', group)
    print('medal', medalcolor)
    print('point',point)
    for j in group:
        print('j', j,checklist[j-1])
        if point == checklist[j-1][0]:
            orders[checklist[j-1][1]-1] = score
            samenum +=1
            nextgroup.append(checklist[j-1][1])
            nextgroupnum += 1
            print('same', orders)
        else:
            if medalcolor <3 and nextgroupnum != 1:
                print('nextgroup', nextgroup)
                makingorder(nextgroupnum, nextgroup, medalcolor +1)
            point = checklist[j-1][0]
            score += samenum
            orders[checklist[j-1][1]-1] = score
            nextgroup = [j]
            nextgroupnum = 0
            print('not same', orders)
    if medalcolor <3 and nextgroupnum != 1 :
         print('nextgroup', nextgroup)
         makingorder(nextgroupnum, nextgroup, medalcolor +1)
    return

makingorder(N,temp[0],1)
