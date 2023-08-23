#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int a[5005], b[5005], c[5005];
    int lena, lenb, lenc, i;
    char n[5005], n1[5005], n2[5005];
 
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
 
    cin >> n1 >> n2;
 
    lena = strlen(n1);
    lenb = strlen(n2);
 
    for(i=0; i<lena; i++) a[lena - i] = (int)n1[i] - '0';
    for(i=0; i<lenb; i++) b[lenb - i] = (int)n2[i] - '0';
 
    i = 1;
    while(i <= lena || i <= lenb) {
        if(a[i] < b[i]) {
            c[i] = a[i] + 10 - b[i];
            a[i+1]--;
        }
        else {
            c[i] = a[i] - b[i]; 
        }
        i++;
    }
 
    lenc = i;
    while(c[lenc] == 0 && lenc > 1) {
        lenc--; 
    }
 
    for(i=lenc; i>=1; i--) cout << c[i];
 
    return 0;
}