#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    freopen("T44.in","r",stdin);
    freopen("T44.out","w",stdout);
    srand((unsigned int)time(NULL));
    cout<<rand();
    fclose(stdin);
    fclose(stdout);
}