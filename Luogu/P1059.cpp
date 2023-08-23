#include<iostream>
#include<algorithm>
using namespace std;
int num[101];
int main(){
    int n,flag=0,ans=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int a;
        cin>>a;
        for(int w = 1;w<=i-1;w++){
            if(a==num[w]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            num[++ans]= a;
        }
        flag = 0;
    }
    sort(num+1,num+1+ans);
    cout<<ans<<endl;
    for(int i = 1;i<=ans;i++){
        cout<<num[i]<<" ";
    }
    return 0;
} 