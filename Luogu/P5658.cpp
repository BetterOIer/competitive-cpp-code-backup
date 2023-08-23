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
    char kuoh;
    int fa;
    long long sum=0;
    long long cnt=0;
    vector<int> sons;
};
node tree[500005];
int top=0, pre[500005];
void dfs(int x)
{
	int tmp = 0;
	if(tree[x].kuoh == ')')
	{
		if(top)
		{
			tmp = pre[top];
			tree[x].cnt = tree[tree[tmp].fa].cnt + 1;
			--top; 
		}
	}
	else if(tree[x].kuoh == '(') pre[++top] = x; 
	tree[x].sum = tree[tree[x].fa].sum + tree[x].cnt;
	for(int i:tree[x].sons) dfs(i);
	if(tmp != 0) pre[++ top] = tmp;
	else if(top) --top; 
}
int main(){
    int n=read();
    string s;
    cin>>s;
    for(int i = 0;i<=n-1;i++) tree[i+1].kuoh=s[i];
    for(int i = 2;i<=n;i++){
        tree[i].fa=read();
        tree[tree[i].fa].sons.push_back(i);
    }
    dfs(1);
    long long ans=0;
    for(int i = 1;i<=n;i++) ans^=(tree[i].sum*(long long)i);
    cout<<ans;
}