#include<iostream>
#include<cstdio>
using namespace std;
int she[10][10]={};
int main(){
    int a, t,fx = 1 ,x = 1,y = 1;
    cin>>a;
    t = a*a;
    for(int i = 1;i<=t;i++){
        if(fx == 1){
            if(x>a||she[y][x]){
                fx++;
                x--;
                y++;
                i--;
            }
            else{
                she[y][x] = i;
                x++;
            }
        }
        else if(fx == 2){
            if(y>a||she[y][x]){
                fx++;
                x--;
                y--;
                i--;
            }
            else{
                she[y][x] = i;
                y++;
            }
        }
        else if(fx == 3){
            if(x<1||she[y][x]){
                fx++;
                x++;
                y--;
                i--;
            }
            else{
                she[y][x] = i;
                x--;
            }
        }
        else if(fx == 4){
            if(y<1||she[y][x]){
                fx=1;
                x++;
                y++;
                i--;
            }
            else{
                she[y][x] = i;
                y--;
            }
        }
    }
    for(int i = 1;i<=a;i++){
        for(int w = 1;w<=a;w++){
            printf("%3d", she[i][w]);
        }
        printf("\n");
    }
    return 0;
} 