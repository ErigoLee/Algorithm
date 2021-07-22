import math
import itertools
N = 0
T = []
s = []

##입력값 받기
while(True):
    N = int(input())
    if 1<=N and N<=8:
        break

factor_num = math.factorial(N)

for i in range(1,N+1,1):
    T.append(i)
s =itertools.permutations(T)
for k in s:
    for j in range(0,N,1):
        print(k[j],end=" ")
    print()