#include<iostream>
#include<algorithm>
#include<array>
using namespace std;
int main(){
    int a[13]={1,5,2,4,5,5,2,36,4,33,64,2,452};
    cout<<max(a+0,a+12);
}