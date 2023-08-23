#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
//#include<queue>
#include<vector>
//#include<stack>
using namespace std;
vector <int> Q;
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n,m,b;
    cin>>n>>m;

    for(int i = 1;i<=n;i++){
        cin>>b;
        Q.push_back(b);
    }
    for(int i = 1;i<=m;i++){
        cin>>b;
        cout<<Q[b-1]<<endl;
    }
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}
