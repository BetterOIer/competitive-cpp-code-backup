#include<iostream>
#include<vector>
#include<map>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct NODE{
    long long num;
    long long tim;
    long long add=0;
};
struct node{
    int s[2];
    int fa;
    long long val;
    long long cnt;
    long long size;
    void init(int fanew,long long valnew,long long timnew){
        fa=fanew,val=valnew;
        cnt=size=timnew;
    }
}tree[1000005];
int root,n,idx,k,all=0;
vector<NODE>V;
vector<int>Temp;
map<long long,int>M;
void pushup(int pos){
    tree[pos].size=tree[tree[pos].s[0]].size+tree[tree[pos].s[1]].size+tree[pos].cnt;
}
void rotate(int pos){
    int fa=tree[pos].fa,grandfa=tree[fa].fa;
    int fich = tree[fa].s[1]==pos;
    tree[fa].s[fich]=tree[pos].s[fich^1];
    tree[tree[pos].s[fich^1]].fa=fa;
    tree[pos].s[fich^1]=fa;
    tree[fa].fa=pos;
    tree[grandfa].s[tree[grandfa].s[1]==fa]=pos;
    tree[pos].fa=grandfa;
    pushup(fa),pushup(pos);
}
void splay(int pos,int goal){
    while(tree[pos].fa!=goal){
        int fa=tree[pos].fa,grandfa=tree[fa].fa;
        if(grandfa!=goal) ((tree[fa].s[0]==pos)^(tree[grandfa].s[0]==fa))? rotate(pos):rotate(fa);
        rotate(pos);
    }
    if(goal==0) root=pos;
}
long long get_kth(int k){
    int pos=root;
    while(true){
        int fich=tree[pos].s[0];
        if(tree[fich].size+tree[pos].cnt<k){
            k-=(tree[fich].size+tree[pos].cnt);
            pos=tree[pos].s[1];
        }else{
            if(tree[fich].size>=k)pos=tree[pos].s[0];
            else break;
        }
    }
    splay(pos,0);
    return tree[pos].val;
}
void insert(long long val,long long tim){
    long long pos=root,fa=0;
    while(pos&&tree[pos].val!=val) fa=pos,pos=tree[pos].s[val>tree[pos].val];
    if(pos)tree[pos].cnt+=tim;
    else{
        pos=++idx;
        tree[fa].s[val>tree[fa].val]=pos;
        tree[pos].init(fa,val,tim);
    }
    splay(pos,0);
}
void out(int n){
    for(int i = 1;i<=(1<<n);i++){
        cout<<get_kth((1<<n)-i+2)<<endl;
    }
}
int main(){
    freopen("kth.in","r",stdin);
    freopen("kth.out","w",stdout);
    n=read(),k=read();
    insert(-1e9,1);insert(1e9,1);
    insert(0,1);
    V.push_back((NODE){0,1});
    M[0]=0;
    for(int i = 1,num;i<=n;i++){
        num=read();
        int len=V.size();
        for(int j = 0;j<len;j++){
            long long nu1=V[j].num+num;
            if(M.find(nu1)==M.end()){
                M[nu1]=++all;
                V.push_back((NODE){nu1,V[j].tim});
            }else{
                V[M[nu1]].add=V[j].tim;
                Temp.push_back(M[nu1]);
            }
            insert(nu1,V[j].tim);
        }
        for(auto j:Temp){
            V[j].tim+=V[j].add;
            V[j].add=0;
        }
        Temp.clear();
    }
    cout<<get_kth((1<<n)-k+2);
}