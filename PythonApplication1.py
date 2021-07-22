##value
min = 1000000
max =  -1000000
a = list()
##main
N =int(input())
a = list(map(int,input().split()))

for i in a:
    if min > i:
        min = i
    if max < i:
        max = i

print("%d %d"%(min,max))