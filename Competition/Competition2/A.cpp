#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    char a;
    int b;
    cin>>s;
    a = s[0];
    b= s[1]-48;
    if(a=='b'||a=='c'||a=='d'||a=='e'||a=='f'||a=='g'){
        if(b == 8||b==1){
            cout<<5;
        }else if(b>=1&&b<=7){
            cout<<8;
        }
    }
    else if(a == 'a'||a == 'h'){
        if(b == 8||b==1){
            cout<<3;
        }else if(b>=1&&b<=7){
            cout<<5;
        }
    }
    return 0;
} 