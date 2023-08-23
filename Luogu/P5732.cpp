#include<iostream>
using namespace std;
int yhsj[21][21];
int main(){
    int a;
    cin>>a;
    yhsj[1][1]=1;
    for(int i=1;i<=a-1;++i){
        yhsj[i+1][1] = 1;
        yhsj[i+1][i+1] = 1;
        for(int j=2;j<=i;++j){
            yhsj[i+1][j]=yhsj[i][j]+yhsj[i][j-1];
        }
    
    }
    for(int i=1;i<=a;++i){
        for(int w=1;w<=i;++w){
            cout<<yhsj[i][w]<<" ";
        }
        cout<<endl;
    }
    return 0;
} 