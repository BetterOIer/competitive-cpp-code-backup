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
int a[21][21],ans=0,n,f[205],g[205],pre[205];
void show(){
    for(int i= 1;i<=n;i++){
        for(int w = 0;w<=n;w++){
            cout<<a[i][w]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    cin>>n;
    for(int i= 1;i<=n;i++){
        cin>>a[i][0];
        a[i][i]=1;
    }
    for(int i= 1;i<n;i++){
        for(int w = i+1;w<=n;w++){
            cin>>a[i][w];
        }
    }
    for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (a[j][i]&&f[j]>f[i]) {
				f[i]=f[j];
				pre[i]=j;
			}
		}
		f[i]+=a[i];
		if (f[i]>ans) {
			ans=f[i];
			t=i;
		}
	}
 	//fclose(stdin); 
    //fclose(stdout);
    return 0;
}