triangle = list()
def max(a,b):
    if a>=b:
        return a
    else:
        return b


def solution(triangle):
    num = len(triangle)
    for i in range(0,num,1):
        num2 = len(triangle[i])
        if num2>1:
            for j in range(0,num2,1):
                if j == 0:
                    triangle[i][j] += triangle[i-1][j]
                elif j == i:
                    triangle[i][j] += triangle[i-1][j-1]
                else:
                    num_max = max(triangle[i-1][j-1],triangle[i-1][j])
                    triangle[i][j] +=num_max

    maximum = triangle[num-1][0]
    num3 = len(triangle[num-1])
    for i in range(1,num3,1):
        if maximum < triangle[num-1][i]:
            maximum = triangle[num-1][i]

    return maximum

##main##
num=int(input())
for i in range(0,num,1):
    a = list(map(int,input().split()))
    triangle.append(a)
    a=[]

answer = solution(triangle)
print(answer)