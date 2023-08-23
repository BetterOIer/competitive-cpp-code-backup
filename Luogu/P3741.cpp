#include<iostream>
using namespace std;
int main(){
    int n, sum=0, summax=0;
    bool a=0;
    string s, sc;
    cin>>n>>s;
    
    for(int i = -1;i<=n-1;++i){
        sc = s;
        if(!a){
            for(int w = 0;w<=n-2;++w){
                if(s[w]=='V'&&s[w+1]=='K'){
                    sum++;
                }
            }
            if (sum>summax){
                summax = sum;
            }
            sum=0;
            a=1;
        }
        else{
            if(sc[i]=='V'){
                sc[i]='K';
            }
            else if(sc[i]=='K'){
                sc[i]='V';
            }
            for(int w = 0;w<=n-2;++w){
                if(sc[w]=='V'&&sc[w+1]=='K'){
                    sum++;
                }
            }
            if (sum>summax){
                summax = sum;
            }
            sum=0;
        }
    }
    cout<<summax;
    return 0;
} 