#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int num,t=1000000,ws=7;
        cin>>num;
        while(num/t==0) {t/=10;ws--;}
        for(int w = 1;w<=ws;w++){
            int o = 1;
            for(int f = 1;f<=w;f++) o*=10;
            if((num%o)/(o/10)>=5) num=(num/o+1)*o;
        }
        cout<<num<<endl;
    }
}