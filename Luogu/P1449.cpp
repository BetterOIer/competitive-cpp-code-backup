#include<iostream>
#include<stack>
using namespace std;
stack <int> Q;
int main(){
    char n;
    int k=0;
    while(cin>>n){
        if(n=='@'){
            break;
        }
        if(n>=48&&n<=57){
            k = k*10+n-'0';
        }else if(n=='.'){
            Q.push(k);
            k = 0;
        }
        else{
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            int c;
            if(n=='+')c = a+b;
            else if(n=='-')c = b-a;
            else if(n=='*')c = a*b;
            else if(n=='/')c = b/a;
            Q.push(c);
        }
    }
    cout<<Q.top();
    return 0;
}