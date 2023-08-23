#include<iostream>
using namespace std;
int mghsl[81]={};
int main(){
    int s1, s2, s3,mins=3, maxs,maxh=0,maxp;
    cin>>s1>>s2>>s3;
    maxs = s1+s2+s3;
    for(int i = 1;i<=s1;++i){
        for(int w = 1;w<=s2;++w){
            for(int j = 1;j<=s3;++j){
                mghsl[i+w+j]++;
            }
        }
    }
    for(int i = mins;i<=maxs;++i){
        if(mghsl[i]>maxh){
            maxh = mghsl[i];
            maxp = i;
        }
    }
    cout<<maxp;
    return 0;
} 