#include<iostream>
#include<cstdio>
using namespace std;
#define LP 0.4463
#define MP 0.4663
#define HP 0.5663
int main(){
    int w;
    float p;
    cin>>w;
    if(w>=0&&w<=150){
        p = LP*w;
    }
    else if(w>150&&w<=400){
        p = LP*150+MP*(w-150);
    }
    else if(w>400){
        p = LP*150+MP*250+HP*(w-400);
    }
    printf("%.1f", p);
    return 0;
}