#include<iostream>
#include<map>
using namespace std;
map<string,int>m;
int main(){
    string s;
    cin>>s;
    int n,len=s.length();
    cin>>n;
    for(int i = 0;i+n-1<len;i++){
        ++m[s.substr(i,n)];
    }
    int maxn=0;
    for(auto i : m ){
        maxn=max(maxn,i.second);
    }
    cout<<maxn;
}