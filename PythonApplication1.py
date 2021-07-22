N = 0  ##재료 갯수
S = []  ##신맛
B = []  ##쓴맛
N_set = []
min = 1000000000  ##최솟값
include = []


##함수
def powerSet(k):
    T = []
    if k == N:
        for i in range(0, N, 1):
            if (include[i]):
                T.append(i)
        N_set.append(T)
        return
    include[k] = False
    powerSet(k + 1)
    include[k] = True
    powerSet(k + 1)


##입력값

while (True):
    N = int(input())
    if (0 <= N and N <= 10):
        break

j=0
while (j<N):
    total_s = 1
    total_b = 0

    s, b = map(int,input().split())

    for i in S:
        total_s = total_s * i
    total_s = total_s * s
    if total_s >= 1000000000:
        continue

    for i in B:
        total_b = total_b + i
    total_b = total_b + b
    if total_b >= 1000000000:
        continue

    S.append(s)
    B.append(b)
    j = j+1

for i in range(0, N, 1):
    include.append(True)
##여러 재료가 나오는 경우의 수
powerSet(0)
##신맛과 짠맛 차이 구하기
T = len(N_set)
for i in range(1, T, 1):
    total_s = 1  ##신맛
    total_b = 0  ##짠맛
    diff = 0  ##차이값
    for j in N_set[i]:
        total_s = total_s * S[j]
        total_b = total_b + B[j]
    diff = abs(total_s - total_b)
    if diff < min:
        min = diff
    if min == 0:
        break

print(min)