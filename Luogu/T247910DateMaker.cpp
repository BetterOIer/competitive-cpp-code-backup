#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
long long a[101][5];
int main(){
    freopen("U224536_1.in","w",stdout);
    srand((unsigned)time(NULL));
    /* int n = rand()%100+1; */
    int n = 100;
    cout<<n<<endl;
    for(int i = 1;i<=n;i++){
        if(i*2<=n){
            a[i][1]=i*2;
            /* a[i][2]=rand()%10000000+1; */
            a[i][2]=INT32_MAX;
        }
        if(i*2+1<=n){
            a[i][3]=i*2+1;
            /* a[i][4]=rand()%10000000+1; */
            a[i][4]=INT32_MAX;
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<i<<" "<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<" "<<a[i][4]<<endl;
    }
}