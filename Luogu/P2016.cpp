#include<iostream>
#include<vector>
using namespace std;
vector <int> frto[1505];
int main(){
    int n,fr,to,k;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>fr>>k;
        for(int j = 1;j<=k;j++){
            cin>>to;
            frto[i].push_back(to);
        }
    }
}