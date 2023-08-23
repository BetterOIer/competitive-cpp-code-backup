#include<iostream>
#include<queue>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
};
int card[100005],n,m,k;
int count[605],instk[605];
struct node{
	int opt;
	int st1;
	int st2=0;
};
vector<node>cmmd;
deque<int>stk[306];
bool used[305];
void autoremove(){
	bool flag=1;
	while(flag){
		for(int i = 2;i<=n;i++){
			if(!used[i]){
				if(i==n)flag=false;
				continue;
			}
			if(stk[1].back()==stk[i].back()){
				instk[stk[1].back()]-=2;
				stk[1].pop_back(),stk[i].pop_back();
				if(stk[1].empty())used[1]=false;
				if(stk[i].empty())used[i]=false;
				cmmd.push_back((node){2,1,i});
				break;
			}
			if(i==n) flag=0;
		}
	}
}
int get_new(){
	for(int i = 1;i<=n;i++){
		if(!used[i])return i;
	}
	return -1;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	while(T--){
		n=read(),m=read(),k=read();
		for(int i = 1;i<=m;i++){
			card[i]=read();
			count[card[i]]++;
		}
		stk[1].push_back(card[1]);
		cmmd.push_back((node){1,1,0});
		used[1]=true;
		instk[card[1]]++;
		count[card[1]]--;
		for(int i = 2;i<=m;i++){
			if(stk[1].front()==card[i]){		
				instk[card[i]]--;
				stk[1].pop_front();
				if(stk[1].empty())used[1]=false;
				cmmd.push_back((node){1,1,0});
			}else if(stk[1].back()==card[i]){
				int nex=get_new();
				if(nex!=-1){			
					instk[card[i]]--;
					stk[1].pop_back();
					if(stk[1].empty())used[1]=false;
					cmmd.push_back((node){1,nex});
					cmmd.push_back((node){2,1,nex});
					autoremove();
				}
			}
			else{
				bool flag=true;
				for(int j = 1;j<=n;j++){
					if(!used[i])continue;
					if(stk[j].front()==card[i]){
						cmmd.push_back((node){1,j});
						stk[j].pop_front();
						if(stk[j].empty())used[j]=false;
						instk[card[i]]--;
						flag=false;
						break;
					}
				}
				if(flag){
					if((instk[card[i]]<<1)<count[card[i]]){
						stk[1].push_front(card[i]);			
						instk[card[i]]++;
						cmmd.push_back((node){1,1});
						if(stk[1].size())used[1]=true;
					}else{
						stk[2].push_front(card[i]);		
						instk[card[i]]++;
						cmmd.push_back((node){1,2});
						if(stk[2].size())used[2]=true;
					}
				}
			}
			count[card[i]]--;
		}
		cout<<cmmd.size()<<endl;
		for(node i:cmmd){
			cout<<i.opt<<" ";
			if(i.opt==1){
				cout<<i.st1<<endl;
			}else cout<<i.st1<<" "<<i.st2<<endl;
		}
		cmmd.clear();
		for(int i = 1;i<=n;i++){
			//if(stk[i].size()||used[i])cout<<"IN";
			if(stk[i].size())stk[i].clear();
			used[i]=false;
		}
		for(int i = 1;i<=k;i++){
			//if(instk[i]||count[i])cout<<"IN";
			instk[i]=count[i]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}