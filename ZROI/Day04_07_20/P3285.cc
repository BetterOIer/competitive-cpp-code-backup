#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
int n,m,lastans;
map <int,int> M;
struct FHQTreap
{
	int root,sze,siz[MAXN],son[MAXN][2],faz[MAXN],key[MAXN],L[MAXN],R[MAXN];
	int NewNode(int l,int r)
	{
		siz[++sze]=r-l+1;
		L[sze]=l;
		R[sze]=r;
		son[sze][0]=son[sze][1]=faz[sze]=0;
		key[sze]=rand();
		M[l]=sze;
		return sze;
	}
	void PushUp(int rt)
	{
		faz[son[rt][0]]=rt;
		faz[son[rt][1]]=rt;
		siz[rt]=siz[son[rt][0]]+siz[son[rt][1]]+1+R[rt]-L[rt];
	}
	int Merge(int x,int y)
	{
		if(!x || !y) return x+y;
		if(key[x]<key[y])
		{
			son[x][1]=Merge(son[x][1],y);
			PushUp(x);
			return x;
		}
		else
		{
			son[y][0]=Merge(x,son[y][0]);
			PushUp(y);
			return y;
		}
	}
	void Split(int rt,int pos,int &l,int &r)
	{
		if(!rt) l=r=0;
		else
		{
			if(pos<=siz[son[rt][0]])
			{
				Split(son[rt][0],pos,l,r);
				son[rt][0]=r;
				r=faz[r]=rt;
			}
			else
			{
				Split(son[rt][1],pos-siz[son[rt][0]]-R[rt]+L[rt]-1,l,r);
				son[rt][1]=l;
				l=faz[l]=rt;
			}
			PushUp(rt);
		}
	}
	int FindKth(int rt,int pos)
	{
		if(pos<=siz[son[rt][0]]) return FindKth(son[rt][0],pos);
		pos-=siz[son[rt][0]];
		if(pos-R[rt]+L[rt]-1<=0) return L[rt]+pos-1;
		return FindKth(son[rt][1],pos-R[rt]+L[rt]-1);
	}
	int FindRak(int rt)
	{
		int res=siz[rt]-siz[son[rt][1]];
		while(rt!=root)
		{
			if(son[faz[rt]][1]==rt) res+=siz[faz[rt]]-siz[son[faz[rt]][1]];
			rt=faz[rt];
		}
        printf("getrank: %d return %d\n",rt,res);
		return res;
	}
	void Insert(int pos,int l,int r)
	{
		int x,y;
		Split(root,pos-1,x,y);
		root=Merge(Merge(x,NewNode(l,r)),y);
	}
	void Delete(int l,int r)
	{
		int x,y,z;
		Split(root,r,x,z);
		Split(x,l-1,x,y);
		root=Merge(x,z);
	}
}T;
int main()
{
	scanf("%d %d",&n,&m);
	M[1]=1;
	T.Insert(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y;
		scanf("%d %d",&opt,&x);
		x-=lastans;
		if(opt==4)
		{
			lastans=T.FindKth(T.root,x);
			printf("%d\n",lastans);
			continue;
		}
		if(opt==1)
		{
			scanf("%d",&y);
			y-=lastans;
			int l=(--M.lower_bound(x+1))->first;
			int pos=M[l];
			int r=T.R[pos];
			lastans=T.FindRak(pos)-r+x;
			printf("%d\n",lastans);
			T.Delete(lastans-x+l,lastans-x+r);
			if(x>l) T.Insert(lastans-x+l,l,x-1);
			T.Insert(lastans,y,y);
			if(r>x) T.Insert(lastans+1,x+1,r);
		}
		else if(opt==2)
		{
			int l=(--M.lower_bound(x+1))->first;
			int pos=M[l];
			int r=T.R[pos];
			lastans=T.FindRak(pos)-r+x;
			printf("%d\n",lastans);
			T.Delete(lastans-x+l,lastans-x+r);
			if(x>l) T.Insert(lastans-x+l,l,x-1);
			if(r>x) T.Insert(lastans,x+1,r);
			T.Insert(1,x,x);
		}
		else if(opt==3)
		{
			int l=(--M.lower_bound(x+1))->first;
			int pos=M[l];
			int r=T.R[pos];
			lastans=T.FindRak(pos)-r+x;
			printf("%d\n",lastans);
			T.Delete(lastans-x+l,lastans-x+r);
			if(x>l) T.Insert(lastans-x+l,l,x-1);
			if(r>x) T.Insert(lastans,x+1,r);
			T.Insert(n,x,x);
		}
	}
	return 0;
}
