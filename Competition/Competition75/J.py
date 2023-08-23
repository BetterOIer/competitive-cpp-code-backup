x,y,z=map(int,input().split())
if y<z:
    print("-1")
else:
    k=y-z
    cnt=int(x/k-1)
    x%=k+k;
    while x-y>0:
        x-=k
        cnt+=1
    print(cnt)