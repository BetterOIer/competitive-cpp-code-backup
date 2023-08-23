#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double pi=3.141593;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        cout<<3<<" "<<12<<" "<<2;
    } else if (T == 4) {
        cout<<fixed<<setprecision(3)<<1.0*500/3;
    } else if (T == 5) {
        cout<<(220+260)/(20+12);
    } else if (T == 6) {
        cout<<sqrt(6*6+9*9);
    } else if (T == 7) {
         cout<<110<<" "<<90<<" "<<0;
    } else if (T == 8) {
        cout<<pi*10<<endl<<pi*25<<endl<<4/3*pi*125<<endl;
    } else if (T == 9) {
        cout<<((((1+1)*2)+1*2)+1)*2;
    } else if (T == 10) {
        cout<<9;
    } else if (T == 11) {
        cout<<1.0*100/3;
    } else if (T == 12) {
        cout<<(int)('M'-'A')+1<<endl<<(char)(18+'A'-1);
    } else if (T == 13) {
        cout<<(int)(pow(4/3*pi*(4*4*4+10*10*10),1.0*1/3));
    } else if (T == 14) {
        cout<<50;
    }
    return 0;
}
