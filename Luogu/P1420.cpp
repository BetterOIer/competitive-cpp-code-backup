#include<iostream>
using namespace std;
int main(){
    int n,sum=1, summax = 0, maxi=0, mini=1000;
    cin>>n;
    int a[n+1];
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        if(a[i]+1==a[i+1]){
            sum+=1;
            continue;
        }
        else if(a[i]+1!=a[i+1]){
            if(sum>summax){
                summax = sum;
            }
            sum = 1;
        }
    }
    cout<<summax;
    return 0;
} 