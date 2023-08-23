#include<iostream>
#include<string>
using namespace std;
string F;
void deal(string M){
    int tmp=(int)M.find(F[0]);
    F= F.substr(1,F.length()-1);
    if(tmp==0){
        if(M.length()>1){
            string M2= M.substr(tmp+1,M.length()-1-tmp);deal(M2);
        }
        cout<<M[0];
    }
    else{
        string M1= M.substr(0,tmp);deal(M1);  
        if(tmp!=M.length()-1){
            string M2= M.substr(tmp+1,M.length()-1-tmp);deal(M2);
        }
        cout<<M[tmp];
    }
}
int main(){
    string M;
    cin>>M>>F;
    deal(M);
}