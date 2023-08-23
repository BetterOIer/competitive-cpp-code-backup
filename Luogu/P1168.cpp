#include<iostream>
#include<queue>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
priority_queue<int,vector<int> > q1;
priority_queue<int,vector<int>,greater<int> > q2;
int main(){
	int n=read();q1.push(read());
	cout<<q1.top()<<endl; 
	for (int i=2;i<=n;i++){
		int input=read();
		if (input>q1.top()) q2.push(input);
		else q1.push(input);
		while (abs(int(q1.size()-q2.size()))>1){
			if (q1.size()>q2.size()){q2.push(q1.top());q1.pop();}
			else{q1.push(q2.top());q2.pop();}
        }
		if (i%2) cout<<(q1.size()>q2.size()?q1.top():q2.top())<<endl;
	}
	return 0;
}
