numbers = [0]*5
dictc = dict()
dictn = dict()
for i in range(5):
    card,number = map(str,input().split())
    number = int(number)
    numbers[i] = number
    if card not in dictc:
        dictc[card] = 1
    else : dictc[card] += 1
    if number not in dictn:
        dictn[number] = 1
    else : dictn[number] += 1
numbers.sort()
scores = []

if numbers[4] - numbers[3] == numbers[3] - numbers[2] == numbers[2]- numbers[1] == numbers[1] - numbers[0] == 1:
    if len(dictc) == 1:
        scores.append(numbers[4] + 900)
    else: scores.append(numbers[4] + 500)
elif len(dictc) == 1: scores.append(numbers[4] + 600)
elif 4 in dictn.values():
    scores.append(numbers[1]+800)
elif 3 in dictn.values():
    if dictn[numbers[0]] == 3 : #111??
        if dictn[numbers[3]] == 2: scores.append(numbers[0]*10+numbers[3]+700) #11122
        else : scores.append(numbers[0]+400)
    elif dictn[numbers[4]] == 3: #11222
        if dictn[numbers[0]] == 2 : scores.append(numbers[0]+numbers[2]*10+700) #11222
        else : scores.append(numbers[4]+400) #12333
    else : scores.append(numbers[2]+400) #12223
elif 2 in dictn.values():
    if dictn[numbers[0]] ==2: #aa???
        if dictn[numbers[2]] == 2 and dictn[numbers[4]] == 1: #aabbc
            scores.append(numbers[2]*10 + numbers[0] + 300)
        elif dictn[numbers[2]] == 1 and dictn[numbers[3]] == 2: #aabcc
            scores.append(numbers[3]*10 + numbers[0] + 300)
        else : scores.append(numbers[0] + 200)
    elif dictn[numbers[1]] == 2: #?bb
        if dictn[numbers[4]] == 2:#abbcc
            scores.append(numbers[4]*10 + numbers[1] + 300)
        else : scores.append(numbers[1] + 200) #?bbcd
    elif dictn[numbers[2]] == 2: scores.append(numbers[2]+200)#abccd
    else: scores.append(numbers[3]+200)
else : scores.append(100+numbers[4])

print(max(scores))
