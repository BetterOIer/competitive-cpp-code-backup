#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <shared_mutex>
using namespace std;
long long  n,Q;
long long  w[1000010];
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct sTree
{
	long long  cotag;
	long long  sumtag;
	long long  maxn;
}tree[1000010<<2];

void pushup(long long  now){
	tree[now].maxn=max(tree[now<<1].maxn,tree[now<<1|1].maxn);
}
void codown(long long  now){
	if(tree[now].cotag!=-1145141919810){
		tree[now<<1].sumtag=tree[now<<1|1].sumtag=0;
		tree[now<<1].maxn=tree[now<<1|1].maxn=tree[now].cotag;
		tree[now<<1].cotag=tree[now<<1|1].cotag=tree[now].cotag;
		tree[now].cotag=-1145141919810;
	}
}
void sumdown(long long  now){
	if(tree[now].sumtag){
		codown(now);
		tree[now<<1].maxn+=tree[now].sumtag,tree[now<<1|1].maxn+=tree[now].sumtag;
		tree[now<<1].sumtag+=tree[now].sumtag,tree[now<<1|1].sumtag+=tree[now].sumtag;
		tree[now].sumtag=0;
	}
}
void pushdown(long long  now){
	codown(now),sumdown(now);
}
void build(long long  now,long long  l,long long  r){
	if(l==r){
		tree[now].maxn=w[l];
		tree[now].cotag=-1145141919810;
		tree[now].sumtag=0;
		return ;
	}
	long long  mid=(l+r)>>1;
	build(now<<1,l,mid),build(now<<1|1,mid+1,r);
	pushup(now);
}
void add(long long  now,long long  l,long long  r,long long  x,long long  y,long long  k){
	if(x<=l&&y>=r){
		codown(now);
		tree[now].maxn+=k;
		tree[now].sumtag+=k;
		return ;
	}
	pushdown(now);
	long long  mid=(l+r)>>1;
	if(x<=mid) add(now<<1,l,mid,x,y,k);
	if(y>mid) add(now<<1|1,mid+1,r,x,y,k);
	pushup(now);
} 
void cover(long long  now,long long  l,long long  r,long long  x,long long  y,long long  k){
	if(x<=l&&y>=r){
		tree[now].sumtag=0;
		tree[now].maxn=k;
		tree[now].cotag=k;
		return ;
	}
	pushdown(now);
	long long  mid=(l+r)>>1;
	if(x<=mid) cover(now<<1,l,mid,x,y,k);
	if(y>mid) cover(now<<1|1,mid+1,r,x,y,k);
	pushup(now);
}
long long  query(long long  now,long long l,long long r,long long x,long long y){
	if(x<=l&&y>=r){
		return tree[now].maxn;
	}
	pushdown(now);
	long long  mid=(l+r)>>1;
	long long  res=-9223372036854775807ll - 1;
	if(x<=mid) res=max(res,query(now<<1,l,mid,x,y));
	if(y>=mid+1) res=max(res,query(now<<1|1,mid+1,r,x,y));
	return res;
}
int main(int argc, char const *argv[]){
	n=read(),Q=read();
	for(long long  i=1;i<=n;i++) w[i]=read();
	build(1,1,n);
	for(int i=1;i<=n*4;i++) tree[i].cotag=-1145141919810;
	while(Q--){
		long long  pos,l,r;
		pos=read(),l=read(),r=read();
		if(pos==1){
			long long k=read();
			cover(1,1,n,l,r,k);
		}
		else if(pos==2){
			long long  k=read();
			add(1,1,n,l,r,k);
		}
		else{
			printf("%lld\n",query(1,1,n,l,r));
		}
	}
	return 0;
}
