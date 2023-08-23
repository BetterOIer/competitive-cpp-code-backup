#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	float a;
	int b, c, d, e, f;
	cin>>a;
	b = floor(a);
	d = (a-b)*10 ;//小数位
	c = b%10;//个位
	e = b%100/10;//十位
	f = (b-c-10*e)/100;//百位
	 
	printf("%d.%d%d%d", d, c, e, f) ;
	
	return 0;
	
}
