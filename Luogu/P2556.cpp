#include<iostream>
using namespace std;
int a[640005];
void deal(int col,int len){
    if(col)cout<<128+len<<" ";
    else cout<<len<<" ";
}
int main(){
    int n,o;
    cin>>n;
    n/=8;
    for(int i = 1;i<=n;i++){
        cin>>o;
        for(int j = 8*i;j>8*(i-1);j--){
            a[j]=o&1;
            o=o>>1;
        }
    }
    n*=8;
    int len=0,col;
    a[0]=-1;
    for(int i = 1;i<=n;i++){
        if(a[i]!=a[i-1]){
            if(i==1){
                len=1;
                col=a[i];
            }else{
                deal(col,len);
                len=1;
                col=a[i];
            }
        }else{
            len++;
        }
    }
    deal(col,len);
}