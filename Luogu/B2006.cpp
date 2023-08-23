#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	float x, a, y, b, z;
	cin>>x>>a>>y>>b;
	
	z=(a*x-b*y)/(a-b);
	
	printf("%.2f", z);
	
	return 0;
}
