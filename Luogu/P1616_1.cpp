#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int t;
    int n;
    int h;
}yao[10001];
bool comp(node a,node b){
    return a.h>b.h;
}
int main(){
    int t,m;
    cin>>t>>m;
    for(int i = 1;i<=m;i++){
        cin>>yao[i].t>>yao[i].n;
        yao[i].h=t/yao[i].t*yao[i].n;
    }
    sort(yao+1,yao+m+1,comp);
    /* for(int i = 1;i<=m;i++){
        for(int w = 0;w<=t;w++){
            if(w>=yao[i].t){
                a[i][w]=max(a[i-1][w-yao[i].t]+yao[i].n,a[i-1][w]);
            }
            else{
                a[i][w]=a[i-1][w];
            }
        }
    } */
    cout<<yao[1].h;
    return 0;
}