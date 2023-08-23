#include<iostream>
using namespace std;
int main(){
	int y, x;
	cin>>y;
	if (y%100==0){
		if(y%400==0){
			x = 1;
		} 
		else{
			x = 0;
		}
	}
	else{
		if(y%4==0){
			x = 1;
		}
		else{
			x = 0;
		}
	} 
	cout<<x;
	return 0;
}
