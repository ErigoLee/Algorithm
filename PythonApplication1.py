##function
def compare_find(number):
    if number % 4 == 0 and (number % 100 !=0 or number % 400 == 0):
        print(1)
    else:
        print(0)

##main
number = int(input())
compare_find(number)