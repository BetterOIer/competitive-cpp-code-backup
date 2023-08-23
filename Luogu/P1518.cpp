#include<iostream>
using namespace std;
int flag[11][11], me[20000];
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct two{
    int x;
    int y;
    int d=0;
} b[2];
/* void show(){
    for(int i = 1;i<=10;i++){
        for(int w = 1;w<=10;w++){
            cout<<flag[i][w];
        }
        cout<<endl;
    }
    cout<<endl;
} */
int main(){
    char a;
    int ans = 0;
    int js[5][2];
    for(int i = 1;i<=10;i++){
        for(int w = 1;w<=10;w++){
            cin>>a;
            if(a=='*'){
                flag[i][w]=1;
            }else if(a=='F'){
                b[0].x = w;
                b[0].y = i;
            }else if(a=='C'){
                b[1].x = w;
                b[1].y = i;
            }
        }
    }
    // show();
    while(b[0].x!=b[1].x||b[0].y!=b[1].y){
        me[ans] = b[0].x+b[0].y*10+b[0].d*100+b[1].x*1000+b[1].y*10000+b[1].d*100000;
        ++ans;
        if(flag[b[0].y+dir[b[0].d][0]][b[0].x+dir[b[0].d][1]]==1||b[0].y+dir[b[0].d][0]<1||b[0].y+dir[b[0].d][0]>10||b[0].x+dir[b[0].d][1]<1||b[0].x+dir[b[0].d][1]>10){
            if(b[0].d==3){
                b[0].d = 0;
            }else{
                b[0].d++;
            }
        }else{
            b[0].y+=dir[b[0].d][0];
            b[0].x+=dir[b[0].d][1];
        }
        if(flag[b[1].y+dir[b[1].d][0]][b[1].x+dir[b[1].d][1]]==1||b[1].y+dir[b[1].d][0]<1||b[1].y+dir[b[1].d][0]>10||b[1].x+dir[b[1].d][1]<1||b[1].x+dir[b[1].d][1]>10){
            if(b[1].d==3){
                b[1].d = 0;
            }else{
                b[1].d++;
            }
        }else{
            b[1].y+=dir[b[1].d][0];
            b[1].x+=dir[b[1].d][1];
        }
        for(int i = 0;i<=ans-2;i++){
            if(me[ans-1]==me[i]){
                cout<<0;
                return 0;
            }
        }
    }
    cout<<ans;
    return 0;
} 