sum=list()
while True:
    a, b = map(int,input().split())
    if a==0 and b==0:
        break
    sum_num=a+b
    sum.append(sum_num)

for i in sum:
    print(i)