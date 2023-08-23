#include<iostream>
using namespace std;
int main(){
    int n,a = 1, b = 1;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int w=1;w<=n;w++){
            printf("%02d",a);
            a++;
        }
        printf("\n");
    }
    printf("\n");

    for(int w=1;w<=n;w++){
        for(int q = n*2-2*w;q>0;q--){
            printf(" ");
        }
        for(int p = 1;p<=w;p++){
            printf("%02d",b);
            b++;
        }
        printf("\n");
    }
    return 0;
}