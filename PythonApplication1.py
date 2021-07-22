#value
count = list()
##main
num = int(input())
for i in range(0,num,1):
    sum = 0
    count_2 = 1
    quize = list(input())
    for j in quize:
        if j == 'O':
            sum = sum+count_2
            count_2 = count_2+1
        else:
            count_2 = 1
    count.append(sum)

for i in count:
    print(i)
