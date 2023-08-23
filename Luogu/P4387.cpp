#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int a[100010],b[100010];
stack <int> Q;
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int k,pa=1,pb=1;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>k;
        for(int w =1;w<=k;w++)cin>>a[w];
        for(int w =1;w<=k;w++)cin>>b[w];
        for(;pa<=k;pa++){
            Q.push(a[pa]);
            while(Q.top()==b[pb]){
                Q.pop();
                pb++;
                if(Q.empty())break;
            }
        }
        if(Q.empty())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        while(!Q.empty())Q.pop();
    }
    return 0;
}