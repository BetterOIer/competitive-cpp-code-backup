#include<iostream>
using namespace std;
int main(){
    freopen("plant.in","w",stdout);
    cout<<"1 0\n1000 1000 1 1\n";
    for(int i = 1;i<=1000;i++){
        for(int j = 1;j<=1000;j++){
            cout<<0;
        }
        cout<<endl;
    }
}