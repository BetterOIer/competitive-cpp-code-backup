#include<iostream>
using namespace std;
int a[1001],N,dpf[1001][1001],dps[1001][1001];
void win(int n){
	for(int i=2;i<=n;i++){
		int row=i;
		int col=1;
		while(row<=n){
			int p1=a[col]+dps[col+1][row];
			int p2=a[row]+dps[col][row-1];
			dpf[col][row]=max(p1,p2);			
			p1= dpf[col+1][row];
			p2= dpf[col][row-1];
			dps[col][row]=min(p1,p2);
			col++;row++;			
		}
	}
	cout<<dpf[1][n]<<" "<<dps[1][n]<<endl;
	return;
}
int main(){
    cin>>N;
    for(int i = 1;i<=N;i++){
		scanf("%d",a+i);
		dpf[i][i]=a[i];
	}
	win(N);
    return 0;
}