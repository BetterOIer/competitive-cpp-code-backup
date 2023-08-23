#include<iostream>
using namespace std;
int a[100010];
int main(){
    int n,x,ANS=0,L=0,R=0;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    if(n%2==0){
        for(int i = a[n/2];i<=a[n/2+1];i++){
            L=0,R=0;
            for(int j=1;j<=n;j++){
		        if(j>a[i]) L++;
		        else if(j<a[i]) R++;
	        }
	        int ans=min(L,R);
            if(ans>ANS){
				x=i;
				ANS=ans;
			}
        }
    }else{
        for(int i=a[n/2];i<=a[n/2+2];i++){
            L=0,R=0;
			for(int j=1;j<=n;j++){
		        if(j>a[i]) L++;
		        else if(j<a[i]) R++;
	        }
            int ans=min(L,R);
			if(ans>ANS){
				x=i;
				ANS=ans;
			}
		}
    }
    cout<<ANS<<" "<<x;
    return 0;
}