#include<iostream>
using namespace std;
int main(){
    int w;
    char a,b,c,d,e,f,g,h,i,j,k,l,m;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m;
    w = ((a-48)*1+(c-48)*2+(d-48)*3+(e-48)*4+(g-48)*5+(h-48)*6+(i-48)*7+(j-48)*8+(k-48)*9)%11;
    if(w==10){
        if(m == 88){
            cout<<"Right";
        }
        else{
            cout<<a<<b<<c<<d<<e<<f<<g<<h<<i<<j<<k<<l<<'X';
        }
    }
    else if(w==(m-48)){
        cout<<"Right";
    }
    else{
        m = w + 48;
        cout<<a<<b<<c<<d<<e<<f<<g<<h<<i<<j<<k<<l<<m;
    }
    
    return 0;
}