#include<iostream>
using namespace std;
int main(){
	int apple;
	cin>>apple;
	if(apple==0){
		cout<<"Today, I ate 0 apple.";
	}
	else if(apple==1){
		cout<<"Today, I ate 1 apple.";
	}
	else if(apple>1){
		cout<<"Today, I ate "<<apple<<" apples.";
	}
	return 0;
}
