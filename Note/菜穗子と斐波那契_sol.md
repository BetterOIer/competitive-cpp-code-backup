## Sol.
为求该式

$$\sum_{i=1}^{n-1}a_ia_{i+2}-\sum_{i=2}^{n}a_i^2$$

即求

$$\sum_{i=1}^{n-1}a_ia_{i+2}-a_{i+1}^2$$

对于其中每一项,设$f(i)=a_ia_{i+2}-a_{i+1}^2$

$$\begin{aligned}f(i) & =a_ia_{i+2}-a_{i+1}^2 \\ & = (a_{i+1}+a_{i})a_{i}-(a_{i}+a_{i-1})a_{i+1}\\ & = a_i^2-a_{i+1}a_{i-1}\\ & =a_{i-2}a_i-a_{i-1}^2\\ & =f(i-2)\end{aligned}$$

$a[]=1,1,2,3,5,8\dots$
代入数据得：$f(1)=1,f(2)=-1$
$f(i)=\begin{cases}1&x \bmod 2=0\\-1&x\bmod 2=1\end{cases}$

## AC Code
```cpp
#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    cout<<!(n&1);
    return 0;
}
```