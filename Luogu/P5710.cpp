#include<iostream>
using namespace std;
int main(){
	int n, a, b, c, d;
	cin>>n;
	if(n%2==0&&n>4&&n<=12){
		a = 1;
		b = 1;
		c = 0;
		d = 0;
	}
	else if((n%2==0&&!(n>4&&n<=12))||(!(n%2)==0&&(n>4&&n<=12))){
		a = 0;
		b = 1;
		c = 1;
		d = 0;
	}
	else if(!(n%2==0&&n>4&&n<=12)){
		a = 0;
		b = 0;
		c = 0;
		d = 1;
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<d;
	
	return 0;
} 
