total_number = 0
min_number = 100000
##function
def find(number):
    global total_number
    global  min_number
    if number == 1:
        return False
    for i in range(number-1,1,-1):
        if number % i == 0:
            return
    total_number = number + total_number
    if min_number > number:
        min_number = number

while True:
    T = int(input())
    S = int(input())
    if 0 < T and T <= 10000:
        if 0 < S and S <= 10000:
            break

for i in range(T,S+1,1):
    find(i)

if total_number == 0:
    print(-1)
else:
    print(total_number)
    print(min_number)