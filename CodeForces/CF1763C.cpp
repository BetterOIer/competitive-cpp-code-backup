#include <iostream>
#include <algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n;
long long a[200005];
int main(){
    long long t = read();
    while (t--){
        n = read();
        for (long long i = 1; i <= n; i++) a[i] = read();
        long long ans=0;
        if (n == 1) ans=a[1];
        else if (n == 2) ans=max(2 * abs(a[1] - a[2]), a[1] + a[2]);
        else if (n == 3)ans=max({3 * abs(a[1] - a[2]), 3 * abs(a[3] - a[2]), 3 * a[1], 3 * a[3], a[1] + a[2] + a[3]});
        else{sort(a + 1, a + n + 1);ans=a[n] * n;}
        cout<<ans<<endl;
    }
}