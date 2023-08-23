#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int a[10001];
/* bool comp(int a,int b){
    return a>b;
} */
void swap(int c,int d){
	if(c==d){
		return;
	}
	a[c] = a[c]^a[d];
	a[d] = a[c]^a[d];
	a[c] = a[c]^a[d];
	//cout<<endl;
	//for(int i = 1;i<=n;i++){
	//	cout<<a[i-1]<<" ";
	//}
}
void fastsort(const int L,const int R){
	if(L>=R){
		return;
	}
	int i = L-1,j = R+1,w = rand()%(R-L+1)+L;
	const int m = a[w];
	int k = L;
	while(k<j){
		if(a[k]< m){
			if(i+1!=k){
				swap(k,i+1);
			}
			i++,k++;
		}else if(a[k]==m){
			k++;
		}else if(a[k]>m){
			swap(k,j-1);
			j--;
		}
	}
	fastsort(L,i);
	fastsort(j,R);
}
int main(){
	freopen("P1090_7.in","r",stdin);
    freopen("P1090_7.out","w",stdout);
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n-1;i++){
        fastsort(i-1,n);
        //sort(a+i,a+n+1/*,comp*/);
        ans=ans+a[i]+a[i+1];
        a[i+1] = a[i+1]+a[i];
    }
    cout<<ans;
 	fclose(stdin);
    fclose(stdout);
    return 0;
}