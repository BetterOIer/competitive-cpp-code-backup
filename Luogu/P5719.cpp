#include<iostream>
using namespace std;
int main(){
    int n, k, s1=0,sum1=0, s2=0, sum2 = 0;
    float av1,av2;
    cin>>n>>k;
    for(int i = 1;i<=n;++i){
        if(i%k ==0){
            s1++;
            sum1+=i;
        }
        else{
            s2++;
            sum2+=i;
        }
    }
    av1 = 1.0*sum1/s1;
    av2 = 1.0*sum2/s2;;
    printf("%.1f %.1f", av1, av2);
    return 0;
} 