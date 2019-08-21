N, K = map(int, input().split())
country = [0]*N
for i in range(N):
    country[i] = list(map(int,input().split()))
country.sort(key= lambda x: (-x[1], -x[2], -x[3]))
print(country)
idx = [country[i][0] for i in range(N)].index(K)
print(idx)
while country[idx-1][1:] == country[idx][1:] :
    idx -= 1
print(idx+1)
