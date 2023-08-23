#include<bits/stdc++.h>
using namespace std;
map <string,int> city;
string s1,s2;
int main(){
    int n,ans=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>s1>>s2;
        s1=s1.substr(0,2);
        if(s1!=s2){
            ans+=city[s1+s2];
            city[s2+s1]++;
        }
    }
    cout<<ans;
}
