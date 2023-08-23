#include<iostream>
using namespace std;
struct node{
    int son=0,brother=0,deep=0;
}tree[100005];
int n,ANS=0;
int main(){
    cin>>n;
    tree[1].deep=1;
    for(int i = 1;i<=n;i++){
        ANS=max(ANS,tree[i].deep);
        cin>>tree[i].son>>tree[i].brother;
        if(tree[i].son!=0)tree[tree[i].son].deep=tree[i].deep+1;
        if(tree[i].brother!=0)tree[tree[i].brother].deep=tree[i].deep+1;
    }
    cout<<ANS;
}