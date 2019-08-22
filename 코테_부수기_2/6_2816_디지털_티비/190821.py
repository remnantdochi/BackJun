N= int(input())
channels = [0]*N
for i in range(N):
    channels[i] = input()

k1 = channels.index('KBS1')
k2 = channels.index('KBS2')

if k1<k2:
    for i in range(k1):
        print(1,end="")
    for j in range(k1):
        print(4,end="")

    for i in range(k2):
        print(1, end="")
    for j in range(k2-1):
        print(4,end="")
else:
    for i in range(k1):
        print(1,end="")
    for j in range(k1):
        print(4,end="")

    for i in range(1,k2+1):
        print(1, end="")
    for j in range(k2):
        print(4,end="")
