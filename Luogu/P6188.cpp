#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
struct node{
	ll x,y,id;
} xy[250010];
struct node2{
	ll lenth,s,e;
	char dir;
};
struct node3{
	ll x,y;
};
vector<node2> ans;
char c;
int n;
node chk(char c){
	return ((c=='E')?(node){0,1}:((c=='W')?(node){0,-1}:((c=='S')?(node){1,0}:(node){-1,0})));
}
bool pd1(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
bool pd2(node a,node b){
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
bool pd3(node2 a,node2 b){
	if(a.lenth!=b.lenth) return a.lenth<b.lenth;
	if(a.s!=b.s) return a.s<b.s;
	return a.e>b.e;
}
char work3(node3 a,node3 b){
	if(a.x<b.x) return 'S';
	if(a.x>b.x) return 'N';
	if(a.y<b.y) return 'E';
	return 'W';
}
void work1(){
	for(int i=1;i<n;i++){
		if(xy[i].x==xy[i+1].x&&min(xy[i].id,xy[i+1].id)+1!=max(xy[i].id,xy[i+1].id)){
			if(xy[i].id<xy[i+1].id)
				ans.push_back((node2){abs(xy[i].y-xy[i+1].y),xy[i].id,xy[i+1].id,work3((node3){xy[i].x,xy[i].y},(node3){xy[i+1].x,xy[i+1].y})});
			else
				ans.push_back((node2){abs(xy[i].y-xy[i+1].y),xy[i+1].id,xy[i].id,work3((node3){xy[i+1].x,xy[i+1].y},(node3){xy[i].x,xy[i].y})});
		}
	}
}
void work2()
{
	for(int i=1;i<n;i++){
		if(xy[i].y==xy[i+1].y&&min(xy[i].id,xy[i+1].id)+1!=max(xy[i].id,xy[i+1].id)){
			if(xy[i].id<xy[i+1].id)
				ans.push_back((node2){abs(xy[i].x-xy[i+1].x),xy[i].id,xy[i+1].id,work3((node3){xy[i].x,xy[i].y},(node3){xy[i+1].x,xy[i+1].y})});
			else
				ans.push_back((node2){abs(xy[i].x-xy[i+1].x),xy[i+1].id,xy[i].id,work3((node3){xy[i+1].x,xy[i+1].y},(node3){xy[i].x,xy[i].y})});
		}
	}
}
int main()
{
	cin>>n;
	xy[0].x=250005;
	xy[0].y=250005;
	for(int i=1;i<=n;i++){
		cin>>c;
		node lead=chk(c);
        xy[i].x=xy[i-1].x+lead.x,xy[i].y=xy[i-1].y+lead.y,xy[i].id=i;
	}
	sort(xy+1,xy+n+1,pd1);work1();
	sort(xy+1,xy+n+1,pd2);work2();
	sort(ans.begin(),ans.end(),pd3);
	cout<<ans[0].lenth<<" "<<ans[0].s<<" "<<ans[0].e<<" "<<ans[0].dir;
	return 0;
}