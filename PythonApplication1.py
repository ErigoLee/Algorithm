##function
def find_click(hour,min):
    if min>=45:
        min=min-45
        print(hour,min)
    else:
        if hour == 0:
            hour = 23
            min = min +60-45
            print(hour,min)
        else:
            hour = hour -1
            min = min + 60 -45
            print(hour, min)

##main
hour, min = map(int,input().split())
find_click(hour,min)
