#include<iostream>
#include<map>
using namespace std;
char base[52]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
map<char, char>M;
int main(){
    int a;
    string s;
    cin>>a>>s;
    a%=52;
    for(int i = 0;i<52;i++) M[base[i]]=base[(i+a+52)%52];
    for(int i = 0;i<=s.length()-1;i++) cout<<M[s[i]];
}