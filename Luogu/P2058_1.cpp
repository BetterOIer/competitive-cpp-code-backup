#include<iostream>
#include<queue>
using namespace std;
struct node{
    int t,ct;
};
queue <node> Q;
int a[100010];
int main(){
    int n,ans=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int tim,k;
        cin>>tim>>k;
        for(int w = 1;w<=k;w++){
            node per;
            per.t=tim;
            cin>>per.ct;
            if(!a[per.ct]) ans++;
            a[per.ct]++;
            Q.push(per);
        }
        k=Q.size();
        for(int w = 1;w<=k;w++){
            node per=Q.front();
            if(per.t+86400<=tim){
                a[per.ct]--;
                if(!a[per.ct]){
                    ans--;
                }
                Q.pop();
                continue;
            }
            break;
        }
        cout<<ans<<endl;
    }
    return 0;
}