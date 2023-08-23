#include<iostream>
#include<cstdio>
using namespace std;
int s[25][25][25];
int  w(int a,int b,int c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }else if(a>20||b>20||c>20){
        return w(20,20,20);
    }else if(a<b&&b<c){
        if(!s[a][b][c-1]){
            s[a][b][c-1]=w(a,b,c-1);
        }
        if(!s[a][b-1][c-1]){
            s[a][b-1][c-1]=w(a,b-1,c-1);
        }
        if(!s[a][b-1][c]){
            s[a][b-1][c]=w(a,b-1,c);
        }
        s[a][b][c] = s[a][b][c-1]+s[a][b-1][c-1]-s[a][b-1][c];
        return(s[a][b][c]);
    }else{
        if(!s[a-1][b][c]){
            s[a-1][b][c]=w(a-1,b,c);
        }
        if(!s[a-1][b-1][c]){
            s[a-1][b-1][c]=w(a-1,b-1,c);
        }
        if(!s[a-1][b][c-1]){
            s[a-1][b][c-1]=w(a-1,b,c-1);
        }
        if(!s[a-1][b-1][c-1]){
            s[a-1][b-1][c-1]=w(a-1,b-1,c-1);
        }
        s[a][b][c] = s[a-1][b][c]+s[a-1][b-1][c]+s[a-1][b][c-1]-s[a-1][b-1][c-1];
        return(s[a][b][c]);
    }
}
int main(){
    int a,b,c;
    while(true){
        scanf("%d%d%d",&a,&b,&c);
        if(a==-1&&b==-1&&c==-1){
            break;
        }
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c));
    }
    return 0;
} 