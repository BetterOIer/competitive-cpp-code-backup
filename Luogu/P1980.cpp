#include<iostream>
using namespace std;
int main(){
    long long n, x, sum, w, a;
    cin>>n>>x;
    for(int i = 1;i<=n;++i){
        a = i;
        do
        {
            w = a%10;
            if (w==x){
                sum++;
            }
            a = (a-w)/10;
        }
        while(a>0);
    }
    cout<<sum;
    return 0;
} 