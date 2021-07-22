N = 0
root = []
left = []
right = []
str_front =[]
str_middle=[]
str_back=[]

##(root)(left)(right)
def front_recursive(index):
    if root[index]=='.':
        return
    str_front.append(root[index])
    front_recursive(root.index(left[index])) ##left
    front_recursive(root.index(right[index])) ##right


##(left)(root)(right)
def middle_recursive(index):
    if root[index] == '.':
        return
    middle_recursive(root.index(left[index]))  ##left
    str_middle.append(root[index])
    middle_recursive(root.index(right[index]))  ##right

##(left)(right)(root)
def back_recursive(index):
    if root[index]=='.':
        return
    back_recursive(root.index(left[index])) ##left
    back_recursive(root.index(right[index])) ##right
    str_back.append(root[index])

##main##
while True:
    N = int(input())
    if 1 <= N and N <= 26:
        break

##input
for i in range(0, N, 1):
    A, B, C = input().split()
    root.append(A)
    left.append(B)
    right.append(C)
root.append('.')
left.append('.')
right.append('.')

##front_recursive
front_recursive(0)
for i in str_front:
    print(i,end="")
print()
##middle_recursive
middle_recursive(0)
for i in str_middle:
    print(i,end="")
print()
##back_recursive
back_recursive(0)
for i in str_back:
    print(i,end="")