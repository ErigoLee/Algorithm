##function
def compare_find(number):
    if number>=90:
        print('A')
    elif number >= 80:
        print('B')
    elif number >= 70:
        print('C')
    elif number >= 60:
        print('D')
    else:
        print('F')

while True:
    number = int(input())
    if 0<= number and number <= 100:
        break

compare_find(number)
