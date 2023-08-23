import math
def f(x):
    return math.factorial(x)
n,m=map(int,input().split())
A1=f(n+2)
A2=f(m)
C1=(f(n+3)/f(m))/f(n+3-m)
A3=2
A4=A1/(n+2)
C2=(f(n+2)/f(m))/f(n+2-m)
ans=A1*A2*C1-A3*A4*A2*C2
print(int(ans))