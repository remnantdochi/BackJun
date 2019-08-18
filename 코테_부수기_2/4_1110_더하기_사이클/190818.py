N = int(input())

def making(N):
    if N < 10 : return N*10 + N
    else :
        return (N//10 + N%10) % 10 + (N%10)*10

cnt = 1
first = making(N)

while first != N:
    first = making(first)
    cnt +=1

print(cnt)
