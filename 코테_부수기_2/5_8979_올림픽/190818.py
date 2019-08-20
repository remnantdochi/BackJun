N, K = map(int, input().split())
medals = [[0]*4]*N
orders = [0]*N



for i in range(N):
    medals[i] = list(map(int,input().split()))
temp = list(zip(*medals))
print('temp',temp)
for i in range(1,4):
    check = [temp[i],temp[0]]
    medalorder = list(zip(*check))

    print('before sort',medalorder)
    medalorder.sort(reverse = True)
    point = medalorder[0][0]
    print('afters sort',medalorder)
    score = 10**(3-i)
    for j in range(N):
        if point == medalorder[j][0]:

            orders[medalorder[j][1]-1] += score
            print('same',j, medalorder[j])
            print(orders)
        else:

            point = medalorder[j][0]
            score += 10**(3-i)
            orders[medalorder[j][1]-1] += score
            print('not same',j, medalorder[j])
            print(orders)
    #print('add value', orders)
