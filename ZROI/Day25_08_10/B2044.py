""" a,b,c=map(int,input().split())
ans=(a<60)+(b<60)+(c<60)
print(int(ans==1)) """


a,b,c=map(int,input().split())
ans=0
if a<60:
    ans+=1
if b<60:
    ans+=1
if c<60:
    ans+=1
if ans==1:
    print(1)
else:
    print(0)