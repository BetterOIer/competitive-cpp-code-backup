#include<iostream>
using namespace std;
int main(){
    string s;
    int ans=0;
    cin>>s;
    for(auto i = 0;i<=s.length()-1;i++){
        if(s[i]=='1'){
            ans++;
        }
    }
    cout<<ans;
}