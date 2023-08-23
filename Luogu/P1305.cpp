#include<iostream>
using namespace std;
string S[27];
int n;
int check(char a){
    for(int i = 1;i<=n;i++){
        if(S[i][0]==a) return i;
    }
    return 0;
}
void deal(int deep){
    cout<<S[deep][0];
    if(S[deep][1]!='*') deal(check(S[deep][1]));
    if(S[deep][2]!='*') deal(check(S[deep][2]));
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>S[i];
    deal(1);
}