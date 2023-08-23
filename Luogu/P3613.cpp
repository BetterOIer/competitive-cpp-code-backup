#include<iostream>
#include<vector>
using namespace std;vector <vector <int> > Q(100000);int main(){int n,q;cin>>n>>q;while(q-->0){int opt,w,j;cin>>opt;if(opt==1){int k;cin>>w>>j>>k;if (j>Q[w].size())Q[w].resize(j+1,1);Q[w][j]=k;}else if(opt==2){cin>>w>>j;cout<<Q[w][j]<<endl;}}return 0;}