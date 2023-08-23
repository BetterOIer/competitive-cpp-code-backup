#include<iostream>
using namespace std;
int a=0,c=0;
int lxws(string s,int x){
    if(x == s.length()-1){
        return 0;
    }
    if(s[x]==s[x+1]){
        if(s[x]==1)a++;
        else c++;
        return(lxws(s,x+1));
    }else{
        return x;
    }
}
int main(){
    string s;
    int amin = 1000000, x,bmax = 0;
    cin>>s;
    x = lxws(s,0)+1;
    while(a!=0||c!=0){
        amin = amin>a? a:amin;
        bmax = bmax>c? bmax:c;
        a = 0;
        c=0;
        lxws(s,x);
    }
    cout<<bmax-amin;
    return 0;
} 