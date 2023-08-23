#include<iostream>
using namespace std;
string uzip(){
    int k;
    char ch;
    string s="",str="";
	while(cin>>ch){
		if(ch=='['){
			cin>>k;
			str=uzip();
			while(k--){
				s+=str;
			}
		}
		else if(ch==']'){
			return s;
		}
		else{
			s+=ch;
		}
	}
}
int main(){
	cout<<uzip();
	return 0;
}