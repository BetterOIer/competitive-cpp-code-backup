#include<bits/stdc++.h>
using namespace std;
unordered_map <string,int> ad;
string s;
bool check(string s){
    int a=0,e=0,po=0,k1=0,k2=0;
    for(int i = 0;i<=s.length()-1;i++){
        if(s[i]=='.')k1++;
        else if(s[i]==':')k2++;
    }
    if(k1!=3||k2!=1) return false;
    for(int i = 0;i<=s.length()-1;i++){
        if(s[i]=='.'||s[i]==':'){
            string s1=s.substr(po,i-po);
            po=i+1,a=0;
            if(s1.length()==0) return false;
            else if(s1.length()>3) return false;
            else if(s1.length()>1&&s1.length()<=3&&s1[0]=='0') return false;
            for(int j=0;j<=s1.length()-1;j++){
                a=a*10+s1[j]-'0';
            }
            if(a>255) return false;
        }
    }
    string s1=s.substr(po,s.length()-po);
    if(s1.length()==0) return false;
    else if(s1.length()>5) return false;
    else if(s1.length()>1&&s1.length()<=5&&s1[0]=='0') return false;
    for(int j=0;j<=s1.length()-1;j++){
        e=e*10+s1[j]-'0';
    }
    if(e>65535) return false;
    return true;
}
int main(){
    int n,k=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s=="Server"){
            cin>>s;
            ++k;
            if(check(s)){
                if(ad.find(s)==ad.end()){
                    ad[s]=k;
                    cout<<"OK"<<endl;
                }else{
                    cout<<"FAIL"<<endl;
                }
            }else{
                cout<<"ERR"<<endl;
            }
        }else if(s=="Client"){
            cin>>s;
            ++k;
            if(ad.find(s)!=ad.end()){
                cout<<ad[s]<<endl;
            }else{
                if(check(s)) cout<<"FAIL"<<endl;
                else cout<<"ERR"<<endl;
            }
        }
    }
    return 0;
}