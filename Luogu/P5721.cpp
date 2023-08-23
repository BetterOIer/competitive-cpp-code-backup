#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n, a = 1;
    cin>>n;
    for(int i= 1;i<=n;++i){
        for(int w = 1;w<=(n+1-i);++w){
            printf("%02d", a);
            a++;
        }
        printf("\n");
    }
    return 0;
} 