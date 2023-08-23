#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    int n;
    cin>>n>>s;
    int pl=s.find("na");
    while(pl!=-1){
        string neww;
        neww=s.substr(0,pl)+"nya"+s.substr(pl+2,n-pl-2);
        swap(s,neww);
        pl=s.find("na");
        n=s.length();
    }
    cout<<s;
    return 0;
}