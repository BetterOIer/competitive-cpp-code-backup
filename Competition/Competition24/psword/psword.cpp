#include<iostream>
using namespace std;
int n,len=0;
string s;
string s1;
int main(){
	freopen("psword.in","r",stdin);
	freopen("psword.out","w",stdout);
	cin>>s;
	cin>>n;
	cout<<26*(s.length()+1)-s.length();
	fclose(stdin);
	fclose(stdout);
} 
