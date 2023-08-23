#include<iostream>
using namespace std;
int tree[260],mc[260],n;
void check(int x){
    if(x >= 1<<n) return;
    check(2*x);
	check(2*x+1);
    if(tree[2*x]>tree[2*x+1]){
        tree[x]=tree[2*x];
        mc[x]=mc[2*x];
    }else{
        tree[x]=tree[2*x+1];
        mc[x]=mc[2*x+1];
    }
}
int main(){
    cin>>n;
    for(int i = 0;i<=(1<<n)-1;i++){
        cin>>tree[i+(1<<n)];
        mc[i+(1<<n)]=i+1;
    }
    check(1);
    if(tree[2]>tree[3]) cout<<mc[3];
    else cout<<mc[2];
    return 0;
}