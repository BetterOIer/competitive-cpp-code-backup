#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,c = 1,d;
	cin>>a>>b;
	for(int i = 1;i<=b;i++){
		c = c*a%7;
		
	}
	if(c==1)
	cout<<"Monday";
	if(c==2)
	cout<<"Tuesday";
	if(c==3)
	cout<<"Wednesday";
	if(c==4)
	cout<<"Thursday";
	if(c==5)
	cout<<"Friday";
	if(c==6)
	cout<<"Saturday";
	if(c==0)
	cout<<"Sunday";
	return 0;
}