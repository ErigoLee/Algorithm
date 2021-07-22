##failed code
##funtion
def sort_work(arr):
    arr_len = len(arr)
    for i in range(0,arr_len-1,1):
        if (arr[i]>arr[i+1]):
            temp = arr[i]
            arr[i] = arr[i+1]
            arr[i+1] = temp
        for j in arr:
            print(j,end=" ")
        print()

    max = 0
    max_idex = 0
    for i in range(0,arr_len,1):
        if max < arr[i]:
            max = arr[i]
            max_idex = i
    print()

    if max_idex != arr_len-1:
        sort_work(arr)
##main
arr = list(map(int,input().split()))
sort_work(arr)
