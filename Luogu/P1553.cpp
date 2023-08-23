#include<iostream>
#include<string>
using namespace std;
unsigned long long a = 0;
string szfz(string s){
    string s1;
    char b;
    if(s=="0"||s=="00"||s=="000"||s=="0000"||s=="00000"||s=="000000"||s=="0000000"||s=="00000000"||s=="000000000"||s=="0000000000"){
        s1 = "0";
    }
    else {
        for(int i = 0;i<=s.length()-1;++i){
            a = 10*a+s[i]-'0';
        }
        while(a!=0){
            if(a%10==0&&s1=="");
            else{
                b = a%10+'0';
                s1+=b; 
            }
            a = (a-a%10)/10;
        }
    }
    return s1;
}
int main(){
    string s, s1, s2;
    cin>>s;
    if((int)s.find(".")==-1&&(int)s.find("/")==-1&&(int)s.find("%")==-1){
        s = szfz(s);
    }else if(s.find(".")!=-1){
        s1 = s.substr(0,s.find("."));
        s2 = s.substr(s.find(".")+1,s.length()-s.find("."));
        s1 = szfz(s1);
        s2 = szfz(s2);
        s = s1+"."+s2;
    }else if(s.find("/")!=-1){
        s1 = s.substr(0,s.find("/"));
        s2 = s.substr(s.find("/")+1,s.length()-s.find("/"));
        s1 = szfz(s1);
        s2 = szfz(s2);
        s = s1+"/"+s2;
    }else if(s.find("%")!=-1){
        s = szfz(s.substr(0,s.length()-1))+"%";
    }
    cout<<s;
    return 0;
}