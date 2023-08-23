#include<iostream>
#include<stack>
using namespace std;
stack <char> S;
int main(){
    string s;
    cin>>s;
    for(int i = 0;i<=s.length()-1;i++){
        if(s[i]=='(') S.push(s[i]);
        else if(s[i]==')'){
            if(S.size()) S.pop();
            else{
                cout<<"NO";
                return 0;
            }
        }
    }
    if(S.size()) cout<<"NO";
    else cout<<"YES";
    return 0;
}