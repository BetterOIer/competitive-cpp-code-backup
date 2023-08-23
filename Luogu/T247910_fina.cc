#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct node{
    int F,L,R,C,len=1;
    long long res[250]={1};
}a[110];
queue <int> Q;
long long RES[1000];
int LEN=1;
void cheng(int x,int who,int child){ 
	int p=0;
    a[child].len=a[who].len;
	for(int i=0;i<a[child].len;i++){
	 	a[child].res[i]=a[who].res[i]*x+p;
	 	p=a[child].res[i]/10;
	 	a[child].res[i]%=10;
	}
	while(p){
	 	a[child].res[a[child].len]=p;
	 	p/=10;
	 	a[child].res[a[child].len++]%=10;
	}
}
void add(int who){
	int l=max(LEN,a[who].len),p=0;
	LEN=l;
	for(int i=0;i<l;i++){
		RES[i]=RES[i]+a[who].res[i]+p;
		p=RES[i]/10;
		RES[i]%=10;
	}
	if(p) RES[LEN++]=p;
}
int main(){
    int n,ro,f1,s1,f2,s2,root;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>ro>>f1>>s1>>f2>>s2;
        if(f1) a[ro].L=f1,a[f1].F=ro,a[f1].C=s1;
        if(f2) a[ro].R=f2,a[f2].F=ro,a[f2].C=s2;
    }
    for(int i = 1;i<=n;i++){
        if(a[i].F==0){
            root=i;
            break;
        }
    }
    Q.push(root);
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        if(a[now].L){
            Q.push(a[now].L);
            cheng(a[a[now].L].C,now,a[now].L);
            add(a[now].L);
        }
        if(a[now].R){
            Q.push(a[now].R);
            cheng(a[a[now].R].C,now,a[now].R);
            add(a[now].R);
        }
    }
    for(int i = LEN-1;i>=0;i--){
        cout<<RES[i];
    }
}