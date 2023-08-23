#include<bits/stdc++.h>
using namespace std;
string s,s1;
char start;
stack <char> room;
void dfs(int L,int po,int R){
    for(int i = 0;i<=po-1;i++){
        room.push(s1[i]);
    }
    for(int i = po+1;i<=2*po;i++){
        char now=room.top();room.pop();
        if(now==s1[i]) continue;
        while(room.size()) room.pop();
        for(int j = i+1;j<=R;j++){
            dfs(i,j,R);
        }
    }
}
int main(){
    
    cin>>s;
    s1=s;
    for(int i = 1;i<=s.length()-2;i++){
        dfs(0,i,s.length()-1);
        s1=s;
    }
}