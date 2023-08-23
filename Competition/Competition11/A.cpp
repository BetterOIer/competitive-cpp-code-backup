#include<bits/stdc++.h>
using namespace std;
int main(){
    int k = 0;
    string s;
    getline(cin,s);
    for(int i = 0;i<=s.length()-1;i++){
        if(s[i]!=' ')k++;
    }
    cout<<k;
}