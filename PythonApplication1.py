##value
count = list()
##main
num = int(input())
for i in range(0,num,1):
    b = list(map(int,input().split()))
    sum = 0
    for j in range(1,len(b),1):
        sum = sum +b[j]
    averge = sum/b[0]
    count_2 = 0
    for j in range(1,len(b),1):
        if b[j] > averge:
            count_2 = count_2+1
    temp = count_2/b[0] * 100
    count.append(temp)
for i in count:
    print("%0.3f%%"%i)