//failed code
##main
chars = list(input())
check = list(input())
last = list()

num = len(chars)

i=0
while i < num:
    index = 0
    for a in range(0,len(check)):
        if chars[i] == check[a]:
            index = 1
            i = i + 1

    if index == 0:
        last.append(chars[i])
        i = i + 1

if len(last) == 0:
    print("FRULA")
else:
    for a in last:
        print(a,end="")
