#include<iostream>
using namespace std;
int main(){
    int l,m,sum = 0;
    cin>>l>>m;
    int tree[l+1]={};
    for(m;m>0;--m){
        int a, b;
        cin>>a>>b;
        for(a;a<=b;++a){
            if(!tree[a]){
                tree[a]=1;
            }
        }
    }
    for(int i = 0;i<=l;++i){
        if(!tree[i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
} 