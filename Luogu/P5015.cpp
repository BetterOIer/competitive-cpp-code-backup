#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    int sum = 0;
    while(cin>>s){
        sum+=s.length();
    }
    cout<<sum;
    return 0;
} 