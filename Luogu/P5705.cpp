#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	float a;
	int b, c, d, e, f;
	cin>>a;
	b = floor(a);
	d = (a-b)*10 ;//С��λ
	c = b%10;//��λ
	e = b%100/10;//ʮλ
	f = (b-c-10*e)/100;//��λ
	 
	printf("%d.%d%d%d", d, c, e, f) ;
	
	return 0;
	
}
