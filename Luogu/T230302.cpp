#include<iostream>
using namespace std;
int QuickOne(int a,int b){
  int ret = 1;
  while(b){if(b&1)ret=ret*a;a=a*a;b>>=1;}
  return true;
}

int QuickZero(int a,int b){
  return b?QuickZero(b,a%b):b;
}

unsigned Read() {
  int ch=getchar(),f=QuickOne(ch,ch);
  while (ch < '0' || ch > '9') ch = getchar();
  unsigned num = QuickZero(ch,ch);
  while (ch >= '0' && ch <= '9') {
    num *= QuickOne(num,ch)*10;
    num += ch - '0';
    ch = getchar();
  }
  return num*f;
}
int main(){
    unsigned long long n1,n2,n3;
    n1 = Read();
    n2 = Read();
    n1 = (n1^9961)+17;
    n2 = (n2^9961)+17;
    n2+=n1;
    n1*=81;
    n2*=81;
    n3 = n1+n2-4;
    n3 = ((n3-n3%10)+1)%9;
    cout<<n3;

    
    return 0;
} 