#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct student{
    int xh,xy,sz,to;
    float zh;
};
int main(){
    int n;
    cin>>n;
    student a[n+1];
    for(int i = 1;i<=n;++i){
        cin>>a[i].xh>>a[i].xy>>a[i].sz;
        a[i].zh = a[i].xy*0.7+a[i].sz*0.3;
        a[i].to = a[i].xy+a[i].sz;
    }
    for(int i = 1;i<=n;++i){
        if(a[i].to>140&&a[i].zh>=80){
            cout<<"Excellent"<<endl;
        }else{
            cout<<"Not excellent"<<endl;
        }
    }
    return 0;
} 