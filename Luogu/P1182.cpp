#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
//#include<cctype>
//#include<queue>
//#include<vector>
//#include<stack>
using namespace std;
int a[50001];
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    int L=0,M,R=100000000,ans=0;
    M=L+(R-L)/2;
    while(R<L){
        int k = m;
        for(int i = 1;i<=n;i++){
            if(k>0){
                if(ans+a[i]<=M){
                    ans+=a[i];
                }else{
                    ans=0;
                    k--;
                }
            }else{
                int l_ans=0;
                for(int w = i;w<=n;w++){
                    l_ans+=a[w];
                }
                if(l_ans>)
            }
        }
    }
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}