#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct student{
    string name;
    int ch,ma,eng,to;
};
int main(){
    int n;
    cin>>n;
    student a[n+1];
    for(int i = 1;i<=n;++i){
        cin>>a[i].name>>a[i].ch>>a[i].ma>>a[i].eng;
        a[i].to = a[i].ch+a[i].ma+a[i].eng;
    }
    for(int i = 1;i<=n-1;++i){
        for(int w = i+1;w<=n;++w){
            if(abs(a[i].ch-a[w].ch)<=5&&abs(a[i].ma-a[w].ma)<=5&&abs(a[i].eng-a[w].eng)<=5&&abs(a[i].to-a[w].to)<=10){
                cout<<a[i].name<<" "<<a[w].name<<endl;
            }
        }
    }
    return 0;
} 