while True:
    N = int(input())
    if 1<= N and N <= 100:
        break
star='*'
temp=' '
for i in range(1,N+1,1):
    print("%s%s"%(temp*(N-i),star*i))