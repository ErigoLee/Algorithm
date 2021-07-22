front = list()
back = list()
##main
num = int(input())
i = 0
while i < num:
    front_num, back_num = map(int,input().split())
    if 0 >= front_num or front_num >= 10:
        if 0 >= back_num or back_num >= 10:
            continue
    front.append(front_num)
    back.append(back_num)
    i = i + 1
for i in range(0,num,1):
    value = front[i] + back[i]
    print(value)