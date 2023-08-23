#include<iostream>
using namespace std;
int main(){
    int a, b, c;
    cin>>a>>b>>c;
    if(a>b){
        if(b>c){
            cout<<c<<" "<<b<<" "<<a;
        }
        else if(a>=c){
            cout<<b<<" "<<c<<" "<<a;
        }
        else if(c>a){
            cout<<b<<" "<<a<<" "<<c;
        }
    }
    else if(a<=b){
        if(c>=b){
            cout<<a<<" "<<b<<" "<<c;
        }
        else if(a>=c){
            cout<<c<<" "<<a<<" "<<b;
        }
        else if(c>a){
            cout<<a<<" "<<c<<" "<<b;
        }
    }
    return 0;
}