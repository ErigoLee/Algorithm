num = list()
count = list()
##main
for i in range(0,10,1):
    input_num = int(input())
    num.append(input_num)

for i in range(0,10,1):
    a = num[i] % 42
    if a not in count:
        count.append(a)

print(len(count))