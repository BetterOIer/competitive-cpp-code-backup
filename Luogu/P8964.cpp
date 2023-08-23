//*** Le vent se lève, il faut tenter de vivre ***
#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,t,a[5];
string name[10];
int check(int k){
	string ina,inb;
	string ans1="freopen(\""+name[k]+".in\",\"r\",stdin);",ans2="freopen(\""+name[k]+".out\",\"w\",stdout);";
	cin>>ina>>inb;
	if(ina==ans1&&inb==ans2) return 1;
 	if(ina.substr(0,10)=="//freopen("&&ina.substr(ina.length()-2,2)==");") return 2;
	if(inb.substr(0,10)=="//freopen("&&inb.substr(inb.length()-2,2)==");") return 2;
	return 3; 
}
int main(){
    t=read(),n=read(),m=read();
	for(int i=1;i<=m;i++) cin>>name[i];
	for(int i=1;i<=n;i++,a[1]=a[2]=a[3]=0){
		for(int j=1;j<=m;j++) a[check(j)]++;
		if(a[1]==m) printf("PION2202 RP++.\n");
		else if(a[2]!=0) printf("Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI.\n");
		else printf("Good luck and have fun.\n");
	}
	return 0;
}
