#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <thread>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int mod = 1e9+7;
const int MAXN = 1e6+5;
const int INF = 2147483647;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int t;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n=read();
    int left=0;
    int i;
    for(i = 1;i<=n;i++){
        t=read();
        if(t>=0&&t<=left){
            left++;
        }
        else break;
    }
    cout<<n-left;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
