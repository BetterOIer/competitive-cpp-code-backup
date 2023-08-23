#include<iostream>
#include<map>
using namespace std;
string s,s1,s2;
map <string,string> house;
string find(string ss){
    if(house.find(ss)!=house.end()){
        return house[ss]=find(house[ss]);
    }else return ss;
}
int main(){
    cin>>s;
    while(s!="$"){
        if(s[0]=='#'){
            s1=s.substr(1,s.length()-1);
        }else if(s[0]=='+'){
            s2=s.substr(1,s.length()-1);
            house[s2]=s1;
        }else{
            string ss;
            ss=s.substr(1,s.length()-1);
            cout<<ss<<" "<<find(ss)<<endl;
        }
        cin>>s;
    }
}