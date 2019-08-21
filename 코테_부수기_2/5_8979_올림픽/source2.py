N, K = map(int, sys.stdin.readline().split())

medals = [0]*(N+1)

for _ in range(1, N+1):
    medals[_] = list(map(int, sys.stdin.readline().split()))

gold = medals[K][1]
silver = medals[K][2]
bronze = medals[K][3]

rank = 1
for _ in range(1, N+1):
    # 금메달 비교
    if medals[_][1] > gold:
        rank += 1
    # 금메달이 같을 때만 은메달 비교
    elif medals[_][1] == gold:
        if medals[_][2] > silver:
            rank += 1
        # 은메달이 같을 때만 동메달 비교
        elif medals[_][2] == silver:
            if medals[_][3] > bronze:
                rank += 1
print(rank)
