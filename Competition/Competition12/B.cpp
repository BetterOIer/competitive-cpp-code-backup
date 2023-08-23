#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    string s;
}a[1001];
bool cmp(node a,node b){
    return a.data<b.data;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i].s;
        for(int w = 0;w<=a[i].s.length()-1;w++){
            a[i].data=a[i].data*10+a[i].s[w]-'0';
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1;i<=m;i++){
        int len;
        string d;
        bool flag=false;
        cin>>len>>d;
        for(int w = 1;w<=n;w++){
            if(a[w].s.length()>=len){
                string cnt=a[w].s.substr(a[w].s.length()-len,len);
                if(cnt==d){
                    cout<<a[w].s<<endl;
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)cout<<-1<<endl;
    }
    return 0;
}