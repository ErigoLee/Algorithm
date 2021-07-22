while(True):
    s, b, t = map(int, input().split())
    if 2 <= s and s <= 10000:
        if 2 <= b and b <= 10000:
            if 2 <= t and t <= 10000:
                break
M = (s+b)%t
print(M)
N = (s%t + b%t)%t
print(N)
L = (s*b)%t
print(L)
K = (s%t * b%t)%t
print(K)