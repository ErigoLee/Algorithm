num_2=list()
while True:
    N, X = map(int,input().split())
    if 1<= N and N <= 10000:
        if 1<= X and X <= 10000:
            break

num = list(map(int,input().split()))
for i in num:
    if i < X:
        num_2.append(i)

for i in num_2:
    print(i,end=" ")