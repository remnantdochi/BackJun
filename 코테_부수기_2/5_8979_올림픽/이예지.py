N, K = map(int, input().split())
inputs = [[0]*4]*N
order = [0]*N

for i in range(N):
    inputs[i] = list(map(int,input().split()))
inputs.sort()
medals = list(zip(*inputs))

#print('original medal', medals)
# 일단 금메달부터
gold = [medals[1],medals[0]]
goldorder = list(zip(*gold))
goldorder.sort(reverse = True)

#print('gold',goldorder)

goldsame = [] # >>> silver
current = goldorder[0][0]
currentsame = []
currentnum = 0

score = 0
for item in goldorder:
    if current == item[0]:
        currentsame.append((medals[2][item[1]-1],item[1]))
        order[item[1]-1] = score
        currentnum +=1
        #print('same',item,score,currentsame)
    else :
        if len(currentsame) != 1 : goldsame.append(currentsame)
        currentsame = [(medals[2][item[1]-1],item[1])]
        score += currentnum
        order[item[1]-1] = score
        currentnum = 1
        current = item[0]
        #print('not same', item, score, currentsame)
if len(currentsame) != 1 : goldsame.append(currentsame)
# print('after gold')
# print(order)
# print(goldsame)

#은메달 : 금메달에서 순위가 결정되지 않은 얘들만
silversame = [] #>>bronze
for silverorder in goldsame:

    silverorder.sort(reverse = True)
    #print('silver',silverorder)
    #silversame = []
    current = silverorder[0][0]
    currentsame = []
    currentnum = 0
    score = 0

    for item in silverorder:
        if current == item[0]:
            currentsame.append((medals[3][item[1]-1],item[1]))
            order[item[1]-1] += score
            currentnum +=1
            #print('same',item,score,currentsame)
        else :
            if len(currentsame) != 1 : silversame.append(currentsame)
            currentsame = [(medals[3][item[1]-1],item[1])]
            score += currentnum
            order[item[1]-1] += score
            currentnum = 1
            current = item[0]
            #print('not same', item, score, currentsame)
    if len(currentsame) != 1 : silversame.append(currentsame)
#     print('silver',silverorder,silversame,currentsame)
# print('after silver')
# print(order)
# print(silversame)

for bronzeorder in silversame:
    bronzeorder.sort(reverse= True)
    current = bronzeorder[0][0]
    currentnum = 0
    score = 0
    for item in bronzeorder:
        if current == item[0]:
            order[item[1]-1] += score
            currentnum +=1
            #print('same',item,score,current)
        else :
            score += currentnum
            order[item[1]-1] += score
            currentnum = 1
            current = item[0]
            #print('not same', item, score, current)

print(order[K-1]+1)
