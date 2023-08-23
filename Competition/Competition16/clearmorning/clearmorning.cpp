#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("clearmorning.in","r",stdin);
    freopen("clearmorning.out","w",stdout);
    string s;
    cin>>s;
    for(int i = s.length()-1;i>=0;i--){
        if(s[i]=='2')cout<<5;
        else if(s[i]=='5')cout<<2;
        else if(s[i]=='J')cout<<'L';
        else if(s[i]=='L')cout<<'J';
        else cout<<s[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}