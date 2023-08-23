#include<iostream>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    string s;
    getline(cin,s);
    for(int i = 1;i<=n;i++){
        getline(cin,s);
        while(s[0]==' ')s.erase(0);
        if(s[0]=='#'&&s[1]==' ')ans++;
    }
    cout<<ans;
}