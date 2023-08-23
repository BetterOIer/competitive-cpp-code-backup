#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct node{
    int emp_y,emp_x;
    int octo_y,octo_x;
    int octo_dir;
    int t;
    bool no_octopus=false;
};
queue <node> Q;
int room[101][101];
bool zg[101][101];
int diry[5]={0,-1,0,1,0};
int dirx[5]={0,0,1,0,-1};
int T=0x3f3f3f3f,start_emperor_y,start_emperor_x,end_y,end_x,m,num_octopus,start_octopus_y,start_octopus_x,room_y=0,room_x=0,num_room;

int main(){
    //freopen("1.out","w",stdout);
    cin>>num_room;
    for(int o = 1;o<=num_room;o++){
        room_y=0;
        room_x=0;
        T=0x3f3f3f3f;
        node start;
        start.t=0;
        memset(room,0,sizeof(room));
        memset(zg,false,sizeof(zg));
        //Initialize each sample
        cin>>start_emperor_y>>start_emperor_x>>end_y>>end_x>>m;
        room_y=max(room_y,max(end_y,start_emperor_y));
        room_x=max(room_x,max(end_x,start_emperor_x));
        start.emp_x=start_emperor_x;
        start.emp_y=start_emperor_y;
        zg[start.emp_y][start.emp_x]=true;
        //Initialize emperor
        int x,y;
        for(int i = 1;i<=m;i++){
            cin>>y>>x;
            room[y][x]=1;
            room_y=max(room_y,y);
            room_x=max(room_x,x);
        }
        //Initialize obstacles
        cin>>num_octopus;
        if(num_octopus){
            cin>>start_octopus_y>>start_octopus_x;
            room_y=max(room_y,start_octopus_y);
            room_x=max(room_x,start_octopus_x);
            start.octo_dir=1;
            start.octo_y=start_octopus_y;
            start.octo_x=start_octopus_x;
        }else{
            start.no_octopus=true;
        }
        //Initialize octopus
        Q.push(start);
        while(!Q.empty()){
            node now=Q.front(),next;Q.pop();
            //Final condition
            if(now.emp_y==end_y&&now.emp_x==end_x){
                T=min(T,now.t);
            }
            next.t=now.t+1;
            //Deal with actopus
            if(!now.no_octopus){
                if(now.octo_y+diry[now.octo_dir]<=room_y&&now.octo_x+dirx[now.octo_dir]<=room_x&&now.octo_y+diry[now.octo_dir]>=1&&now.octo_x+dirx[now.octo_dir]>=1){
                    if(room[now.octo_y+diry[now.octo_dir]][now.octo_x+dirx[now.octo_dir]]==1){
                        next.octo_x=now.octo_x;
                        next.octo_y=now.octo_y;
                        next.octo_dir=(now.octo_dir)%4+1;
                    }else{
                        next.octo_y=now.octo_y+diry[now.octo_dir];
                        next.octo_x=now.octo_x+dirx[now.octo_dir];
                        next.octo_dir=(now.octo_dir)%4+1;
                    }
                }else{
                    next.octo_x=now.octo_x;
                    next.octo_y=now.octo_y;
                    next.octo_dir=(now.octo_dir)%4+1;
                }
            }else{
                next.no_octopus=true;
            }
            //Deal with the emperor
            for(int i = 1;i<=4;i++){
                if(now.emp_y+diry[i]>=1&&now.emp_y+diry[i]<=room_y&&now.emp_x+dirx[i]>=1&&now.emp_x+dirx[i]<=room_y&&!zg[now.emp_y+diry[i]][now.emp_x+dirx[i]]){
                    if(room[now.emp_y+diry[i]][now.emp_x+dirx[i]]==0){
                        if((now.emp_x+dirx[i]!=next.octo_x||now.emp_y+diry[i]!=next.octo_y)||(next.no_octopus)){
                            next.emp_x=now.emp_x+dirx[i];
                            next.emp_y=now.emp_y+diry[i];
                            zg[next.emp_y][next.emp_x]=true;
                            Q.push(next);
                        }
                    }
                }
            }
        }
        if(T==0x3f3f3f3f){
            cout<<-1<<endl;
        }else cout<<T<<endl;
    }
}