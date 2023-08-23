#include <iostream>
using namespace std;
#define V 250
int main(){
    int x, n, s;
    cin>>x>>n;
    if (n%7<=(6-x)){
        s = V*n-(n-n%7)/7*2*V;
    }
    else if(n%7<=(8-x)&&n%7>=(7-x)){
        s = V*n-(n-n%7)/7*2*V-V*(n%7-6+x);
    }
    else if(n%7>=(9-x)&&n<=6){
        s = V*n-(n-n%7)/7*2*V-V*2;
    }

    cout<<s;

    return 0;
}