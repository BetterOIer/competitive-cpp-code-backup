#include<iostream>
using namespace std;
bool a[10000001]={1,1};
int b[10000001];
int k;
int hws(long x){
    long w=x,g=0;
    while(w>0){
        g = 10*g + w%10;
        w = (w-w%10)/10;
    }
    if (g!=x){
        return 0;
    }
    return 1;
}
int main()
{
    int n,m;
    cin>>n>>m;
	for(int i=2;i<=10000001;i++)
	{
		if (a[i]==0)	b[++k]=i;	
		for(int j=1;j<=k;j++)
		{
			if(i*b[j]>10000001)break;
			a[i*b[j]]=1;
			if(i%b[j]==0)break;
		}	
	}
    for(int i = 1;i<=10000001;i++){
        if(b[i]<=m&&b[i]>=n)if(hws(b[i]))cout<<b[i]<<endl;
        if(b[i]>=m)break;
    }
	return 0;
 } 