#include<iostream>
using namespace std;
string s1[200005],s2[200005];
int vis[200005];
int ans=0;
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            string s3=s1[i].substr(0,2);
            for(int j = 1;j<=n;j++){
                if(!vis[j]&&s3==s2[j]){
                    string s4=s1[j].substr(0,2);
                    if(s4==s2[i]) ans++;
                }
            }
        }
    }
    cout<<ans;
}