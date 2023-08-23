#include<iostream>
#include<set>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int graph[10][10];
set <int> takenE[10];
set <int> takenH[10];
set <int> takenL[10];
int can[10],cnt=10;
int tot=0;
int ref(int y,int x){
    if(y>=1&&y<=3){
        if(x>=1&&x<=3) return 1;
        else if(x>=4&&x<=6) return 2;
        else if(x>=7&&x<=9) return 3;
        
    }
    else if(y>=4&&y<=6){
        if(x>=1&&x<=3) return 4;
        else if(x>=4&&x<=6) return 5;
        else if(x>=7&&x<=9) return 6;
    }
    else if(y>=7&&y<=9){
        if(x>=1&&x<=3) return 7;
        else if(x>=4&&x<=6) return 8;
        else if(x>=7&&x<=9) return 9;
    }
    return 0;
}
int main(){
    for(int i = 1;i<=9;i++) for(int j = 1;j<=9;j++){
        graph[i][j]=read();
        if(graph[i][j]==0)tot++;
        else{
            takenE[ref(i,j)].insert(graph[i][j]);
            takenH[i].insert(graph[i][j]);
            takenL[j].insert(graph[i][j]);
        }
    }
    while(tot){
        for(int i = 1;i<=9;i++) for(int j = 1;j<=9;j++){
            if(graph[i][j])continue;
            for(int w = 1;w<=9;w++)can[w]=0;
            cnt=10;
            for(auto w:takenE[ref(i,j)]){
                if(!can[w]){cnt--;can[w]=true;}
            }
            for(auto w:takenH[i]){
                if(!can[w]){cnt--;can[w]=true;}
            }
            for(int w:takenL[j]){
                if(!can[w]){cnt--;can[w]=true;}
            }
            if(cnt==1){
                tot--;
                for(int h = 1;h<=9;h++)if(can[h]==false)graph[i][j]=h;
                for(int i = 1;i<=9;i++){
                    for(int j = 1;j<=9;j++){
                        cout<<graph[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
            }
        }
    }
    for(int i = 1;i<=9;i++){
        for(int j = 1;j<=9;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}