##failed code
def rotation(key):
    n = len(key)
    new_key = [[0] * n for _ in range(0, n)]

    for i in range(0,n,1):
        for j in range(0,n,1):
            new_key[j][n-1-i] = key[i][j]
    return new_key

def find(key,block,i,j,n,m,count):
    
    count2 = 0
    for k in range(0,n):
        for t in range(0,n):
            if (k + i >= n and k + i < n + m ) and (t + j >= n and t + j < n + m):
                if (key[k][t] == 1 and block[k+i][t+i] == 0) or (key[k][t] == 0 and block[k+i][t+i] == 1):
                    count2 = count2+1
                else:
                    return False

        if count2 == count:
            return True

    return False

def solution(key, lock):
    answer = False
    count = 0
    n = len(key)
    m = len(lock)
    block = [[0] * (2*n + m) for _ in range(0, 2*n + m)]

    for i in range(0, 2*n + m, 1):
        for j in range(0, 2*n + m, 1):
            if (i - n >= 0 and i - n < m) and (j - n >= 0 and j - n < m):
                block[i][j] = lock[i - n][j - n]
                if lock[i - n][j - n] == 0:
                    count = count + 1
            else:
                block[i][j] = 1

    a = 0
    while a < 4:

        for i in range(1,2*n+m-1,1):
            for j in range(1,2*n+m-1,1):
                answer = find(key,block,i,j,n,m,count)

                if answer == True:
                    return answer

        a=a+1
        key = rotation(key)

    return answer

key_example=[[0,0,0],[1,0,0],[0,1,1]]
lock_example=[[1,1,1],[1,1,0],[1,0,1]]

answer=solution(key_example,lock_example)
print(answer)
