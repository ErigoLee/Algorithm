sum=list()
while True:
    try:
        a, b =map(int,input().split())
    except:
        break
    if 0>=a or a>=10:
        if 0>=b or b>=10:
            continue
    sum.append(a+b)

for i in sum:
    print(i)