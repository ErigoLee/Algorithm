##다음 순열을 찾을 수 있는 함수
def next_permutation():
    i = N-1
    while i > 0 and T[i-1]>=T[i]:
        i = i-1
    if i == 0:
        return False
    j=N-1
    while T[i-1] >= T[j]:
        j = j - 1
    T[i-1],T[j]=T[j],T[i-1]
    j = N - 1
    while i<j:
        T[i],T[j] = T[j],T[i]
        j = j-1
        i = i+1
    return True
##입력값 받기
while(True):
    N = int(input())
    if (1<=N and N<=10000):
        break

##순열값 받기
while(True):
    a = 0
    input_number = map(int,input().split())
    T = list(input_number)
    for i in T:
        if (i > N or i<=0):
            a = a+1
    if a == 0:
        break
S = next_permutation()
if S:
    for i in T:
        print(i,end=" ")
else:
    print(-1)