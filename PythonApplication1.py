count = 0
##function
def find(number):
    if number == 1:
        return False
    for i in range(number-1,1,-1):
        if number % i == 0:
            return False
    return True

while True:
    N = int(input())
    if 0 < N and N <= 1000:
        break

a = list(map(int,input().split()))
for j in a:
    if find(j):
        count = count+1
print(count)