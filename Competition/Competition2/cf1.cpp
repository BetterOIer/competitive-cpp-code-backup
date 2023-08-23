#include<iostream>
#include<windows.h>
using namespace std;
int c=0;
int f(int x){
	if(x<9){
		int s = c;
		c=0;
		return s;
	}
	c++;
	int a[10], m=0;
	while(x>0){
		if(x%10<9){
			a[++m] = x%10;
		}
		x/=10;
	}
	for(int i = m;i>=1;i--){
		x = x*9+a[i];
	}
	Sleep(1000);
	cout<<x<<endl;
	return f(x);
}
int main(){
	int n, x;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x;
		cout<<endl<<f(x)<<endl;
	}
	return 0;
}
