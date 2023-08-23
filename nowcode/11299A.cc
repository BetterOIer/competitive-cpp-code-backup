#include<iostream>
using namespace std;
int main(){
    int hf;
    cin>>hf;
    while(--hf>=0){
        int n,ck=0,cd=0;
        cin>>n;
        for(int i = 1;i<=n;i++){
            string s;
            cin>>s;
            int h=s[0]-'0';
            int m=(s[2]-'0')*10+s[3]-'0';
            if(h==7) continue;
            else if(h==9) ck++;
            else if(h==8){
                if(m==0) continue;
                else if(m>0&&m<=5) cd++;
                else ck++;
            }
        }
        cout<<cd<<" "<<ck<<endl;
    }
}