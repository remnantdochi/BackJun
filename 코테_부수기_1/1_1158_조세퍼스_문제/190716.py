#음 일단 circle로 할까
class node:
    def __init__(self,data,next):
        self.data = data
        self.next = next
class clist:
    def __init__(self,head):
        self.head = head
        self.tail = head
    def add(self,data):
        newnode = node(data,None)
        self.tail.next = newnode
        self.tail = self.tail.next
    def delete(self,point): #그전에서 지울래 ㅠ
        #print("what to delete",point.next.data)
        if point.next != point.next.next:
            point.next = point.next.next
        else: point.next = None
N, K = map(int,input().split())
people = clist(node("1",None))

for i in range(2,N+1):
    people.add(str(i))
people.tail.next = people.head
tpoint = people.head

result = []
cnt = 1

while tpoint != None:
    #print(tpoint.data)
    if cnt == K-1:
        result.append(tpoint.next.data)
        people.delete(tpoint)
        cnt = 1
    else:
        cnt+=1
    tpoint = tpoint.next
print("<"+", ".join(result)+">")
