#include<iostream>
using namespace std;
char a[11][11]={};
char b[11][11]={};
char c[11][11]={};
char d[11][11]={};
int cmp(int n,char x[11][11],char y[11][11]){
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            if(x[i][w]==y[i][w]){
                continue;
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}
void turn_90(int n, char x[11][11]){
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            c[i][w]=x[n+1-w][i];
        }
    }
}
void fanzhuan(int n,char x[11][11]){
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            c[i][w]=x[i][n+1-w]; 
        }
    }
}
void tidai(int n, char x[11][11]){
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            d[i][w]=x[i][w];
        }
    }
}
int main(){
    int n;
    cin>>n;
    //shuru
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            cin>>a[i][w];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            cin>>b[i][w];
        }
    }
    //fangfa1
    turn_90(n, a);
    if (cmp(n,c,b)){
        cout<<1;
        return 0;
    }
    //fangfa2
    tidai(n, c);
    turn_90(n, d);
    if(cmp(n,c,b)){
        cout<<2;
        return 0;
    }
    //fangfa3
    tidai(n, c);
    turn_90(n, d);
    if(cmp(n,c,b)){
        cout<<3;
        return 0;
    }
    //fangfa4
    fanzhuan(n, a);
    if(cmp(n,c,b)){
        cout<<4;
        return 0;
    }
    //fangfa5
    tidai(n, c);
    for(int s = 1;s<=3;++s){
        turn_90(n, d);
        if(cmp(n,c,b)){
            cout<<5;
            return 0;
        }
        tidai(n, c);
    }
    //fangfa6
    if(cmp(n,a,b)){
        cout<<6;
        return 0;
    }
    //fangfa7
    cout<<7;
    return 0;
} 