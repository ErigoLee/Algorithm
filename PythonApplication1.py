while(True):
    s, b = map(int, input().split())
    if 0 < s and s < 10:
        if 0 < b and b < 10:
            break

print(s+b)