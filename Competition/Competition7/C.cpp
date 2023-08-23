#include<iostream>
#include<queue>
using namespace std;
int a[32769];
struct node{
    int t,dj;
};
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int dj;
        cin>>dj;
        if(a[dj]){
            cout<<a[dj]<<" ";
            continue;
        }if(dj==0){
            cout<<0<<" ";
            continue;
        }
        queue <node> Q;
        Q.push((node){0,dj});
        while(!Q.empty()){
            node now=Q.front();
            Q.pop();
            if((now.dj+1)%32768){
                Q.push((node){now.t+1,(now.dj+1)%32768});
            }else{
                cout<<now.t+1<<" ";
                a[dj]=now.t+1;
                break;
            }
            if((now.dj*2)%32768){
                Q.push((node){now.t+1,(now.dj*2)%32768});
            }else{
                cout<<now.t+1<<" ";
                a[dj]=now.t+1;
                break;
            }
        }
    }
    return 0;
}