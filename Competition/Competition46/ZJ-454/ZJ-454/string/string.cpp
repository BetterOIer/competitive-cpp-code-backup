#include<iostream>
using namespace std;
long long n;
long long k;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>k;
    cin>>s;
    long long tot=0;
    while(k>0&&tot<n){
        char maxl='z'+1;
        long long mpo=tot;
        long long maxline=min(tot+k+1,n);
        for(int i = tot;i<maxline;i++){
            if(s[i]<maxl){
                maxl=s[i];
                mpo=i;
            }
        }
        k-=(mpo-tot);
        string next;
        if(tot){string s1=s.substr(0,tot);next+=s1;}
        next+=s[mpo];
        if(mpo-tot>0){string s2=s.substr(tot,mpo-tot);next+=s2;}
        if(n-mpo-1>0){string s3=s.substr(mpo+1,n-mpo-1);next+=s3;}
        swap(next,s);
        tot++;
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}