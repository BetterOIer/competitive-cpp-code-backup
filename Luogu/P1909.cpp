#include<iostream>
#include<cmath>
using namespace std;
int main(){
    float n, a, b;
    int w, w1;
    cin>>n>>a>>b;
    w = ceil(n/a)*b;
    for(int i = 0; i <= 1; ++i){
        cin>>a>>b;
        w1 = ceil(n/a)*b;
        if(w1<w){
            w = w1;
        }
    }
    cout<<w;

    return 0;
}