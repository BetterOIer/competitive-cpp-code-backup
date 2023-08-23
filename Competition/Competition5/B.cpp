#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
//#include<queue>
//#include<vector>
//#include<stack>
using namespace std;
bool a[100000001]={1,1};
int b[100000001],k,ans=0;//存质数 
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=2;i<=n;i++)
	{
		if (a[i]==0)	b[++k]=i;	
		for(int j=1;j<=k;j++)
		{
			if(i*b[j]>n)break;
			a[i*b[j]]=1;
			if(i%b[j]==0)break;
		}	
	}
    for(int i = 1;i<=k;i++){
        if(n%b[i]==0){
            ans+=b[i];
        }
    }
    printf("%08d",ans);
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}