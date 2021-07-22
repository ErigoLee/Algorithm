##main
while True:
    num = int(input())
    if 1 <= num and num <=10000:
        break
sum = 0
for i in range(1,num+1,1):
    sum=sum+i
print(sum)