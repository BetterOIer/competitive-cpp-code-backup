#include<iostream>
#include<set>
#include<map>
using namespace std;
map <string,bool> want;
map <string,int> cnt;
int ans1=0,ans2=0;
string a[100005];
int main(){
    int n,m,l=1;
    cin>>n;
	for(int i=1;i<=n;i++){cin>>a[0];want[a[0]]=1;}
    cin>>m;
    for(int i = 1;i<=m;i++){
        cin>>a[i];
        if(want[a[i]]) cnt[a[i]]++;
        if(cnt[a[i]]==1){
            ans1++;
            ans2=i+1-l;
        }
        for(;l<=i;){
            if(!want[a[l]]){
                l++;
                continue;
            }
            if(cnt[a[l]]>1){
                --cnt[a[l]];
                ++l;
                continue;
            }
            break;
        }
        ans2=min(ans2,i-l+1);
    }
    cout<<ans1<<endl<<ans2;
}