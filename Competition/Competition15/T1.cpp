#include<iostream>
using namespace std;
int main(){
    char a;
    while(cin>>a){
        if(a>='A'&&a<='Z'){
            a=a+32;
            cout<<a;
        }else if(a>='a'&&a<='z'){
            a=a-32;
            cout<<a;
        }else if(a>='0'&&a<='9'){
            a='9'-a+'0';
            cout<<a;
        }
    }
}