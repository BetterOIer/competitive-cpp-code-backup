#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack <int> Q;
int a[110];
string s;
int main(){
    cin>>s;
    for(int i = 0;i<=s.length()-1;i++){
        if(s[i]=='('||s[i]=='[') Q.push(i);
        else{
            if(!Q.empty()){
                if((s[i]==')'&&s[Q.top()]=='(')||(s[i]==']'&&s[Q.top()]=='[')){
                    a[i]=1;
                    a[Q.top()]=1;
                    Q.pop();
                }
            }
        }
    }
    for(int i = 0;i<=s.length()-1;i++){
        if(a[i]==0){
            if(s[i] == '(' || s[i] == ')') cout<<"()";
			else cout<<"[]";
        }else cout<<s[i];
    }
    return 0;
}