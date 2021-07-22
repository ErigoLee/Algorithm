##function
def compare_find(number_1,number_2):
    if number_1 > number_2:
        print('>')
    elif number_1 < number_2:
        print('<')
    else:
        print('==')

while True:
    T, S = map(int,input().split())
    if -10000 < T and T <= 10000:
        if -10000 < S and S <= 10000:
            break

compare_find(T,S)