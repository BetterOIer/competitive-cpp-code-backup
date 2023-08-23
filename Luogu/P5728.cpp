#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int c, sum;
    cin>>c;
    int fenshu[c+1][4];
    for(int i = 1;i<=c;++i){
        for(int w = 1;w<=3;++w){
            cin>>fenshu[i][w];
        }
        fenshu[i][0] = fenshu[i][1]+fenshu[i][2]+fenshu[i][3];
    }
    for(int i = 1;i<=c-1;++i){
        for(int w = i+1;w<=c;++w){
            if(abs(fenshu[i][0]-fenshu[w][0])<=10&&abs(fenshu[i][1]-fenshu[w][1])<=5&&abs(fenshu[i][2]-fenshu[w][2])<=5&&abs(fenshu[i][3]-fenshu[w][3])<=5){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}