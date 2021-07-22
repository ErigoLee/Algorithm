while(True):
    s, b = map(int, input().split())
    if 0 < s and s <= 10000:
        if 0 < b and b <= 10000:
            break

print(s+b)
print(s-b)
print(s*b)
print(s//b)
print(s%b)