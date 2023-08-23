#include<iostream>
#include<string>
char a;
using namespace std;
int main(){
    int n;
    cin>>n;
    while(cin>>a){
        if(a+n>'z'){
            a = 'a'+a+n-'{';
        }
        else{
            a = a+n;
        }
        cout<<a;
    }

    return 0;
} 