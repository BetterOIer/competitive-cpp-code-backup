#include<iostream>
using namespace std;
int L,R,minn,sum;
int s[5];
int a[21][5];
void search(int x,int y){
	if(x>s[y]){
		minn=min(minn,max(L,R));
		return;
	}
	L+=a[x][y];
	search(x+1,y);
	L-=a[x][y];
	R+=a[x][y];
	search(x+1,y);
	R-=a[x][y];
}
int main(){
	for(int i = 1;i<=4;i++){
        cin>>s[i];
    }
	for(int i=1;i<=4;i++){
		L=R=0;
		minn=10000000;
		for(int j=1;j<=s[i];j++)
			cin>>a[j][i];
		search(1,i);
		sum+=minn;
	}
	cout<<sum;
	return 0;
}