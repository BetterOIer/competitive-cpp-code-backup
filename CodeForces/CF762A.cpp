#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector <long long> Q;
int main(){
    long long n;
    long long k;
    cin>>n>>k;
    long long t=sqrt(n);
    for(int i = t;i>=1;i--){
        if(n%i==0){
            if(i==n/i) Q.push_back(i);
            else{Q.insert(Q.begin(),i);
            Q.insert(Q.end(),n/i);}
        }
    }
    if(Q.size()<k){
        cout<<-1;
    }else cout<<Q[k-1];
}