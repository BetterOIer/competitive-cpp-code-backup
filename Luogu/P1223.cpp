#include<iostream>
#include<algorithm>
using namespace std;
struct stud{
    int xh;
    int ti;
}a[1001];
bool comp(stud a,stud b){
    if(a.ti!=b.ti)return a.ti<b.ti;
    else{
        return a.xh<b.xh;
    }
}
int main(){
    int n;
    double sum=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].ti;
        a[i].xh = i;
    }
    sort(a+1,a+n+1,comp);
    for(int i = 1;i<=n;i++){
        cout<<a[i].xh<<" ";
        sum+=a[i].ti*(n-i);
    }
    sum/=n;
    printf("\n%.2f",sum);
    return 0;
} 