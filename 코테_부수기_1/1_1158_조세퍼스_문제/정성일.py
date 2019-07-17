n,k=map(int,input().split())
list=[]

for i in range(1,n+1):
    list.append(i)

print("<",end="")
index=0
for i in range(1,n):
    index=(index+k-1)%len(list)
    print(str(list.pop(index))+", ",end="")
print(str(list.pop(0))+">")
