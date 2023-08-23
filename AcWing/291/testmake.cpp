#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    freopen("P1009_10.in","w",stdout);
    srand((unsigned int)time(NULL));
    int n=100;
    while(n--){
        cout<<rand()%11+1<<" "<<rand()%11+1<<endl;
    }
    cout<<"0 0";
    return 0;
}