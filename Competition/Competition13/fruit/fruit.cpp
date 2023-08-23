#include<bits/stdc++.h>
using namespace std;
struct node{
    int pre,aft,data;
}fruit[200005];
int k=0,flag=-1;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&fruit[i].data);
        fruit[i].pre=i-1;
        fruit[i].aft=i+1;
    }
    fruit[0].aft=1;
    fruit[n].aft=0;
    while(k<n){
        flag=-1;
        for(int i = fruit[0].aft;i!=0;i=fruit[i].aft){
            if(fruit[i].data!=flag){
                flag=fruit[i].data;
                fruit[fruit[i].pre].aft=fruit[i].aft;
                fruit[fruit[i].aft].pre=fruit[i].pre;
                k++;
                printf("%d ",i);
            }
        }
        puts("");
    }
    return 0;
}