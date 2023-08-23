#include<iostream>
#include<string>
using namespace std;
string com(string s1, string s2){
    int sum1=1,sum2=1;
    for(int i = 0;i<=s1.length()-1;++i){
        sum1*=(s1[i]-'A'+1);
    }
    for(int i = 0;i<=s2.length()-1;++i){
        sum2*=(s2[i]-'A'+1);
    }
    
    if(sum1%47==sum2%47){
        return "GO";
    }else{
        return "STAY";
    }
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    cout<<com(s1, s2);
    return 0;
} 