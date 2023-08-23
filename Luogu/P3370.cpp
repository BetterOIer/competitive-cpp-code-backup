#include<iostream>
#include<vector>
#define base 256
using namespace std;
int mod=101527,ans=0;
bool a[101529];
string s;
vector<vector <string> > check(mod+2);
bool find(int sum){
	for(int i=0;i<check[sum].size();i++){
		if(check[sum][i]==s)return 1;
	}
	return 0;
}
void Hash(){
    int cnt=0;
    for(int i = 0;i<=s.length()-1;i++){
        cnt=(cnt*base+s[i])%mod;
    }
    if(!a[cnt]){
            a[cnt]=1;
            check[cnt].push_back(s);
        }
        else{
            if(find(cnt)) return;
            else check[cnt].push_back(s);
        }
        ans++;
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>s;
        Hash();
    }
    cout<<ans;
}