/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
/* #include<map> */
//#include<ctime>
//#include<numeric>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
/* bool a[10000001]={1,1};
int b[664580];//存质数 
int tim[664580];
int maxn[664580];
int minn[664580];
int all[664580];
//int num[100005];
map<int,int>M;
int k; */
/* int ols()
{
    //freopen("P.in","r",stdin);
	for(int i=2;i<=10000000;i++)//这个意思是在100001里面找到质数并且标记 ，质数最小是2，所以i=2 
	{
		if (a[i]==0)	b[++k]=i,M[i]=k;	//如果没有被标记为1，就是质数。我接下来会讲解为什么是质数。 
		for(int j=1;j<=k;j++)//j小于当前所有的质数的个数
		{
			if(i*b[j]>10000000)break;// 如果超出给出的范围，那么就退出循环 
			a[i*b[j]]=1;//用质数数依次×i，结果标记为合数（也就是标记为1）。 
			if(i%b[j]==0)break;//最关键的只标记一次 
		}	
	}
    //cout<<k;
    //for(int i = 1;i<=k;i++){
     //   cout<<b[i]<<endl;
    //}
	return 0;
 } 
void init(){
    for(int i = 1;i<=664579;i++)all[i]=0;
    for(int i = 1;i<=664579;i++)maxn[i]=0;
    for(int i = 1;i<=664579;i++)minn[i]=2147483647;
}
void solve(){
    int n=read();
    for(int i = 1,x;i<=n;i++){
        x=read();
        int cnt=1;
        while(x!=1){
            while(x%b[cnt]==0){
                x/=b[cnt];
                tim[cnt]++;
                all[cnt]++;
            }
            cnt++;
        }
        for(int i = 1;i<=664579;i++){
            maxn[i]=max(tim[i],maxn[i]);
            minn[i]=min(tim[i],minn[i]);
            tim[i]=0;
        }
    }
    bool ans=true;
    for(int i = 1;i<=664579;i++){
        if(maxn[i]+minn[i]!=all[i]){
            ans=false;
            break;
        }
    }
    cout<<(ans? "Yes":"No")<<endl;
} */
int gcd(int __m, int __n)
    {
      while (__n != 0)
	{
	  int __t = __m % __n;
	  __m = __n;
	  __n = __t;
	}
      return __m;
    }
int lcm(int a,int b){
		return a/gcd(a,b)*b;
}
int a[500005];
int l,g;
void solve(){
    int n=read();
    l=g=a[1]=read();
    for(int i = 2;i<=n;i++){
        a[i]=read();
        l=lcm(a[i],l);
        g=gcd(a[i],g);
    }
    for(int i = 2;i<=n;i++){
        a[i]*=a[i-1];
    }
    if(l*g==a[n])cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ////freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
    //int tt=clock();
    //ols();
    int t=read();
    while(t--)solve();
    //cout<<clock()-tt;
    return 0;
}