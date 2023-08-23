#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map <int,int> ball;
int main(){
    int n,Q;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>Q;
        ball[Q]=i;
    }
    cin>>Q;
    for(int i = 1;i<=Q;i++){
        cin>>n;
        if(ball.find(n)!=ball.end()) cout<<ball[n]<<endl;
        else cout<<0<<endl;
    }
}