#include<iostream>
using namespace std;
int main(){
    int k,ans=0;
    cin>>k;
    for(int i = 10000;i<=30000;i++){
        int i1=(i%100000)/10000*100+(i%10000)/1000*10+(i%1000)/100*1;
        int i2=(i%10000)/1000*100+(i%1000)/100*10+(i%100)/10*1;
        int i3=(i%1000)/100*100+(i%100)/10*10+(i%10)/1*1;
        if(i1%k==0&&i2%k==0&&i3%k==0){
            cout<<i<<endl;
            ans++;
        }
    }
    if(!ans) cout<<"No";
}