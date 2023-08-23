#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int L;
    int R;
    int W;
};
vector<node>V,V1;
int main(){
    freopen("T22.in","r",stdin);
    freopen("T22.out","w",stdout);
    int m=read(),n=read(),opt,x,y;
    for(int i = 1;i<=m;i++){
        opt=read();
        if(opt==1){
            x=read(),y=read();
            V.push_back((node){x,y,y+1-x});
        }
        else{
            x=read();
            long long ans=0;
            for(auto pet:V){
                if(pet.L<=x&&x<=pet.R){
                    ans+=pet.W;
                }else{
                    V1.push_back(pet);
                }
            }
            V.clear();
            swap(V,V1);
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
}