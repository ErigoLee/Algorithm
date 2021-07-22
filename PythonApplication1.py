check_ring = list()
##유클리드 호제법
def fun1(i,j):
    while i%j!=0:
        k = i % j
        i = j
        j = k
    return j

def fun2(a,b):

    if a >= b:
        k = fun1(a,b)
    else:
        k = fun1(b,a)

    a = a/k
    b = b/k
    check_ring.append((a,b))

##main
num = int(input())
ring = list(map(int,input().split()))

stand_ring = ring[0]
for i in ring:
    if i == stand_ring:
        continue
    fun2(stand_ring,i)

for j in check_ring:
    print("%d/%d" %(j[0],j[1]))