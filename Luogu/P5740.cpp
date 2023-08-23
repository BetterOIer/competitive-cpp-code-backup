#include<iostream>
using namespace std;
struct stdt {
    string name;
    int ch;
    int ma;
    int eng;
    int to;
};
int main(){
    int n, sum = 0, pm;
    cin>>n;
    stdt a[n+1];
    for(int i = 1;i<=n;i++){
        cin>>a[i].name>>a[i].ch>>a[i].ma>>a[i].eng;
        a[i].to = a[i].ch+a[i].ma+a[i].eng;
        if(sum<a[i].to){
            pm = i;
            sum = a[i].to;
        } 
    }
    cout<<a[pm].name<<" "<<a[pm].ch<<" "<<a[pm].ma<<" "<<a[pm].eng<<" ";
    return 0;
}