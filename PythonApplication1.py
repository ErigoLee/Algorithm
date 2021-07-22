def route_Hanoi(N, from_H, by_H, to_H):
    if N==1:
        print("%d %d"%(from_H,to_H))
    else:
        route_Hanoi(N-1,from_H,to_H,by_H)
        print("%d %d"%(from_H,to_H))
        route_Hanoi(N-1,by_H,from_H,to_H)

N = 0
while(1):
    N = int(input())
    if 1<=N and N<=100:
        break

transform_count = 2**N-1
print("%d" %transform_count)
if N<=20:
    route_Hanoi(N,1,2,3)