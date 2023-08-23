#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
    int po;
    int si;
}mess[40008];
deque <node> Q;
long long ans=0;
bool comp(node a,node b){
    if(a.po==b.po) return a.si>b.si;
    return a.po<b.po;
}
int main(){
    int n,k=1;
    cin>>n;
    for(int i = 1,j=1;i<=2*n;i++,j=0-j){
        cin>>mess[i].po;
        mess[i].si=j;
    }
    sort(mess+1,mess+2*n+1,comp);
    while(k<=2*n){
        Q.push_back(mess[k++]);
        while(!Q.empty()){
            if(mess[k].si==1){
                Q.push_back(mess[k++]);
            }else{
                if(Q.size()==1){
                    ans=ans+mess[k++].po-Q.front().po;
                    Q.pop_back();
                }else{
                    Q.pop_back();
                    k++;
                }
            }
        }
    }
    cout<<ans;
}