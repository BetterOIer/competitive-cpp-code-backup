#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;
stack <int> n1;
stack <int> n2;
int ss[100];
char opt[100];
int k=0;
int Trans_opt(char a){
    if(a=='+'||a=='-')return 1;
    if(a=='*'||a=='/')return 2;
    if(a=='^')return 3;
    return 0;
}
void ysfbj(string s,int i){
    if(n1.empty()||n1.top()=='('){
        n1.push(s[i]);
    }else if(Trans_opt(s[i])>Trans_opt(n1.top())){
        n1.push(s[i]);
    } else {
        n2.push(n1.top());
        n1.pop();
        ysfbj(s,i);
    } 
}
void string_deal(string s){
    for(int i = 0;i<=s.length()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            n2.push(s[i]);
        }else if(s[i]=='('){
            n1.push(s[i]);
        }else if(s[i]==')'){
            while(n1.top()!='('){
                n2.push(n1.top());
                n1.pop();
            }
            n1.pop();
        }else{
            ysfbj(s,i);
        }
    }
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    string s;
    cin>>s;
    string_deal(s);
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}