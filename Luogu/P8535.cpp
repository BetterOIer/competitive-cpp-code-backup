#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans1=n/5,cnt=n%5;
	if (cnt>=3){
		ans1--;
		cout<<"2";
	}
	for (int i=1;i<=ans1;i++) cout<< "1";
	return 0;
}
