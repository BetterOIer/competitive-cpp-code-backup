#include<iostream>
using namespace std;
const int FANWEI = 1000000;
bool s[FANWEI+5]={};
int d[FANWEI]={2};
int b,k = 0;
void prime(int n){
    for (int i = 2;i<=FANWEI;i++){
        if(k==n){
            break;
        }
        if(!s[i]){
            d[++k] = i;
        }
        for(int j = 1;j<=k;j++){
            int x = i*d[j];
            if(x>FANWEI){
                break;
            }
            s[x] = 1;
            if(i%d[j]==0){
                break;
            }
        }
    }
}
int main(){
    int n,t;
    bool flag = 0;
    cin>>n;
    prime(n);
    for(int j = 4;j<=n;j+=2){
        t = j/2;
        for(int i = 1;i<=t&&flag == 0;i++){
            for(int w = i;w<=j&&flag == 0;w++){
                if(j-d[i]==d[w]){
                    cout<<j<<'='<<d[i]<<'+'<<d[w]<<endl;
                    flag = 1;
                }
            }
        }
        flag = 0;
    }
    return 0;
}