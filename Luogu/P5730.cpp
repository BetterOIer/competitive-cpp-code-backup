#include<iostream>
#include<cstdio>
using namespace std;
int xsp[6][400] = {};
int main(){
    int n;
    char c;
    cin>>n;
    for(int i = 0; i<=n;++i){
        scanf("%c", &c);
        if(c-'0'==0){
            xsp[1][4*i-3] = 1;
            xsp[1][4*i-2] = 1;
            xsp[1][4*i-1] = 1;
            xsp[2][4*i-3] = 1;
            xsp[2][4*i-1] = 1;
            xsp[3][4*i-3] = 1;
            xsp[3][4*i-1] = 1;
            xsp[4][4*i-3] = 1;
            xsp[4][4*i-1] = 1;
            xsp[5][4*i-3] = 1;
            xsp[5][4*i-2] = 1;
            xsp[5][4*i-1] = 1;
        }
        else if(c-'0'==1){
            xsp[1][4*i-1] = 1;
            xsp[2][4*i-1] = 1;
            xsp[3][4*i-1] = 1;
            xsp[4][4*i-1] = 1;
            xsp[5][4*i-1] = 1;
        }
        else if(c-'0'==2){
            xsp[1][4*i-3] = 1;
            xsp[1][4*i-2] = 1;
            xsp[1][4*i-1] = 1;
            xsp[2][4*i-1] = 1;
            xsp[3][4*i-3] = 1;
            xsp[3][4*i-2] = 1;
            xsp[3][4*i-1] = 1;
            xsp[4][4*i-3] = 1;
            xsp[5][4*i-3] = 1;
            xsp[5][4*i-2] = 1;
            xsp[5][4*i-1] = 1;
        }
        else if(c-'0'==3){
            xsp[1][4*i-3] = 1;
            xsp[1][4*i-2] = 1;
            xsp[1][4*i-1] = 1;
            xsp[2][4*i-1] = 1;
            xsp[3][4*i-3] = 1;
            xsp[3][4*i-2] = 1;
            xsp[3][4*i-1] = 1;
            xsp[4][4*i-1] = 1;
            xsp[5][4*i-3] = 1;
            xsp[5][4*i-2] = 1;
            xsp[5][4*i-1] = 1;
        }
        else if(c-'0'==4){
            xsp[1][4*i-3] = 1;
            xsp[1][4*i-1] = 1;
            xsp[2][4*i-3] = 1;
            xsp[2][4*i-1] = 1;
            xsp[3][4*i-3] = 1;
            xsp[3][4*i-2] = 1;
            xsp[3][4*i-1] = 1;
            xsp[4][4*i-1] = 1;
            xsp[5][4*i-1] = 1;
        }
        else if(c-'0'==5){
            xsp[1][4*i-3] = 1;
            xsp[1][4*i-2] = 1;
            xsp[1][4*i-1] = 1;
            xsp[2][4*i-3] = 1;
            xsp[3][4*i-3] = 1;
            xsp[3][4*i-2] = 1;
            xsp[3][4*i-1] = 1;
            xsp[4][4*i-1] = 1;
            xsp[5][4*i-3] = 1;
            xsp[5][4*i-2] = 1;
            xsp[5][4*i-1] = 1;
        }
        else if(c-'0'==6){
            xsp[1][4*i-3] = 1;
            xsp[1][4*i-2] = 1;
            xsp[1][4*i-1] = 1;
            xsp[2][4*i-3] = 1;
            xsp[3][4*i-3] = 1;
            xsp[3][4*i-2] = 1;
            xsp[3][4*i-1] = 1;
            xsp[4][4*i-3] = 1;
            xsp[4][4*i-1] = 1;
            xsp[5][4*i-3] = 1;
            xsp[5][4*i-2] = 1;
            xsp[5][4*i-1] = 1;
        }
        else if(c-'0'==7){
            xsp[1][4*i-3] = 1;
            xsp[1][4*i-2] = 1;
            xsp[1][4*i-1] = 1;
            xsp[2][4*i-1] = 1;
            xsp[3][4*i-1] = 1;
            xsp[4][4*i-1] = 1;
            xsp[5][4*i-1] = 1;
        }
        else if(c-'0'==8){
            xsp[1][4*i-3] = 1;
            xsp[1][4*i-2] = 1;
            xsp[1][4*i-1] = 1;
            xsp[2][4*i-3] = 1;
            xsp[2][4*i-1] = 1;
            xsp[3][4*i-3] = 1;
            xsp[3][4*i-2] = 1;
            xsp[3][4*i-1] = 1;
            xsp[4][4*i-3] = 1;
            xsp[4][4*i-1] = 1;
            xsp[5][4*i-3] = 1;
            xsp[5][4*i-2] = 1;
            xsp[5][4*i-1] = 1;
        }
        else if(c-'0'==9){
            xsp[1][4*i-3] = 1;
            xsp[1][4*i-2] = 1;
            xsp[1][4*i-1] = 1;
            xsp[2][4*i-3] = 1;
            xsp[2][4*i-1] = 1;
            xsp[3][4*i-3] = 1;
            xsp[3][4*i-2] = 1;
            xsp[3][4*i-1] = 1;
            xsp[4][4*i-1] = 1;
            xsp[5][4*i-3] = 1;
            xsp[5][4*i-2] = 1;
            xsp[5][4*i-1] = 1;
        }
    }
    for(int i = 1;i<=5;i++){
        for(int w = 1;w<=n*4-1;w++){
            if(xsp[i][w]){
                cout<<"X";
            }
            else{
                cout<<".";
            }
        }
        cout<<endl;
    }
    return 0;
} 