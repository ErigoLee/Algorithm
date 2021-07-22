while True:
    N = int(input())
    if 1<= N and N <= 100:
        break
star='*'
for i in range(1,N+1,1):
    print(star*i)