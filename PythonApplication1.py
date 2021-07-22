num = int(input())
num2=num
b = 1
while True:
    if num2 < 10:
        t = 0
        s = num2
    else:
        t = num2//10
        s = num2%10
    temp = (t+s)%10
    num2 = s*10 + temp
    if num2 == num:
        break
    b = b+1
print(b)