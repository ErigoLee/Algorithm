##value
count = list()
##main
num1 = int(input())
num2 = int(input())
num3 = int(input())
sum = num1*num2*num3
sum_list = list(map(int,str(sum)))

for i in range(0,10,1):
    count.append(0)

for i in sum_list:
    count[i] = count[i]+1

for i in count:
    print(i)