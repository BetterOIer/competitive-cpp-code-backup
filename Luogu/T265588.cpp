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
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
	string v;
	long long loc;
	bool operator <(const node &x)const {
		if(v.length()!=x.v.length()) return v.length()>x.v.length();
		return v>x.v;
	}
}a[500005];
string w[500005];
map<char,char>s;
long long k,n;
int main(){
	k=read(),n=read();
	for(int i=0;i<k;i++){
		char c;
		cin>>c;
		if(i<=9)s[c]=i+48;
		else if(i<=35)s[c]=i+'A'-10;
		else s[c]=i+'a'-36;
	}
	for(int i=1;i<=n;i++){
		cin>>w[i];
        int st=0;
        string ans;
        while(s[w[i][st]]=='0'&&st<w[i].length()-1)st++;
        for(int j=st;j<w[i].length();j++) ans+=s[w[i][j]];
		a[i].v=ans;
		a[i].loc=i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) cout<<w[a[i].loc]<<" "; 
	return 0;
}