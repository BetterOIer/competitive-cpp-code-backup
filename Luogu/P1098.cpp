#include<iostream>
using namespace std;
string s;
void deal(int po,int p1,int p2,int p3){
    string s2;
    if(s[po-1]=='-'||s[po+1]=='-'||po-1<0||po+1==s.length()){
        return;
    }
    char l = s[po-1],r = s[po+1];
    if(l>=r||(isdigit(l)&&isalpha(r))){
        return;
    }
    if(l+1==r){
        s.erase(po,1);
        return;
    }
    if(isalpha(l)&&isalpha(r)){
    l = s[po-1]-32*(p1-1),r = s[po+1]-32*(p1-1);
    }
    if(p3==1){
        for(int i = l+1;i<=r-1;i++){
            char a = i;
            for(int w = 1;w<=p2;w++){
                if(p1==3){
                    s2+='*';
                }else{
                    s2+=a;
                }
            }
        }
    }
    else if(p3==2){
        for(int i = r-1;i>=l+1;i--){
            char a = i;
            for(int w = 1;w<=p2;w++){
                if(p1==3){
                    s2+='*';
                }else{
                    s2+=a;
                }
            }
        }
    }
    s.erase(po,1);
    s = s.substr(0,po)+s2+s.substr(po,s.length()-po);
    return;
}
int main(){
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    cin>>s;
    for(int i = 0;i<=s.length()-1;i++){
        if(s[i]=='-'){
            deal(i,p1,p2,p3);
        }
    }
    cout<<s;
    return 0;
} 