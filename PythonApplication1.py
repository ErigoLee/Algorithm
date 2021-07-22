##function
def compare_find(num1,num2,num3):
    if num1 > num2:
        if num2 > num3:
            print(num2)
        else:
            if num3 > num1:
                print(num1)
            else:
                print(num3)
    else:
        if num1 > num3:
            print(num1)
        else:
            if num3>num2:
                print(num2)
            else:
                print(num3)

##main
while True:
    num1,num2,num3 = map(int,input().split())
    if 1<= num1 and num1 <= 100:
        if 1<=num2 and num2 <= 100:
            if 1<=num3 and num3 <=100:
                break

compare_find(num1,num2,num3)
