#include<iostream>
using namespace std;
int a[101];
int main(){
    
    int n, sum = 0;
    cin>>n; 
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i= 1;i<=n;++i){
        for(int w=1;w<=n;++w){
            if(w==i){
                continue;
            }
            for(int j=w+1;j<=n;++j){
                if(j==i){
                    continue;
                }
                if(a[i]==a[w]+a[j]){
                    sum++;
                }
            }
        }
    }
    cout<<sum;
    return 0;
} 