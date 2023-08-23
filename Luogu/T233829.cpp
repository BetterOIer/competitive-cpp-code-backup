#include<iostream>
using namespace std;
int xx[10],re=9;
int a[10000005],b[10000005],c[10000005],d=5,e[10000005];
int main(){
    int ans=0;
    string s1,s2,s;
    bool flag=true;
    for(int i = 0;i<=9;i++){
        cin>>xx[i];
        ans+=xx[i];
    }
    for(int i = 9;i>=0;i--){
        while(xx[i]--)s+=(i+'0');
    }
    for(int i =0,j=1;i<s.length();j+=2,i+=2){
        if(j==s.size()){
            if(flag) s1+=s[i];
            else s2+=s[i];
            break;
        }
        if(flag&& s[i]==s[j]){
            s1+=s[i],s2+=s[i];
        }else if(flag) s1+=s[i],s2+=s[j],flag=0;
        else s2+=s[i],s1+=s[j];
    }
    int flg;
    if(s1[s1.length()-1]=='0'){
        for(int i=1;i<s1.length(); i++) {
            a[i-1]=s1[s1.length()-i-1]-'0';
        }
        for(int i=0; i<s2.length(); i++) {
            b[i]=s2[s2.length()-i-1]-'0';
        }
        flg=1;
        d=2;
        for(int i=0; i<s1.length()-1; i++) {
            int carry=0;
            c[i]+=a[i]*d+carry;
            carry=c[i]/10;
            c[i]%=10;
            c[i+1]+=carry;
        }
        int index=s1.length();
        while(c[index]==0 && index>0) index--;
        for(int i=index; i>=0; i--) cout<<c[i];
        cout<<endl;
        d=5;
        for(int i=0; i<s2.length(); i++) {
            int carry=0;
            e[i]+=b[i]*d+carry;
            carry=e[i]/10;
            e[i]%=10;
            e[i+1]+=carry;
        }
        index=s2.length()+1;
        while(e[index]==0 && index>0) index--;
        for(int i=index; i>=0; i--) cout<<e[i];
    }else{
        for(int i=0;i<s1.length(); i++) {
            a[i]=s1[s1.length()-i-1]-'0';
        }
        for(int i=1; i<s2.length(); i++) {
            b[i-1]=s2[s2.length()-i-1]-'0';
        }
        flg=2;
        d=2;
        for(int i=0; i<s1.length(); i++) {
            int carry=0;
            c[i]+=a[i]*d+carry;
            carry=c[i]/10;
            c[i]%=10;
            c[i+1]+=carry;
        }
        int index=s1.length()+1;
        while(c[index]==0 && index>0) index--;
        for(int i=index; i>=0; i--) cout<<c[i];
        cout<<endl;
        d=5;
        for(int i=0; i<s2.length()-1; i++) {
            int carry=0;
            e[i]+=b[i]*d+carry;
            carry=e[i]/10;
            e[i]%=10;
            e[i+1]+=carry;
        }
        index=s2.length();
        while(e[index]==0 && index>0) index--;
        for(int i=index; i>=0; i--) cout<<e[i];
    }
	return 0;
}
