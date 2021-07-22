a = 0
b = 0
temp = 0
max = 0
num = list()
while True:
    try:
        n = int(input())
        num.append(n)
        if max < n:
            max = n
            b = a+1
        a = a + 1
    except:
        break
num.sort()
print(num[len(num)-1])
print(b)
