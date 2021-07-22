max = 0
##main
num = int(input())
a = list(map(int,input().split()))
sum = 0
for i in a:
    if max < i:
        max = i
for i in range(0,num,1):
    a[i] = a[i]/max * 100
for i in a:
    sum = sum + i
print("%0.2f"%(sum/num))