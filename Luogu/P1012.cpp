#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct cyz{
    string n;
}a[5001];
int comp(cyz a,cyz b){
    string s1 = a.n+b.n,s2 = b.n+a.n;
    for(int i = 0;i<=s1.length()-1;i++){
        if(s1[i]==s2[i]){
            continue;
        }else{
            return s1[i]>s2[i];
        }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].n;
    }
    sort(a+1,a+n+1,comp);
    for(int i = 1;i<=n;i++){
        cout<<a[i].n;
    }
    return 0;
} 