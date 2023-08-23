#include<iostream>
#include<cstdio>
using namespace std;

int trigonometric(int a,int b){
    if (a < b || a * b != 0) {
        for (int i = 2; i <= a; ++i) {
            if (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
            } 
            else {
                continue;
            }
        }
        for (int i = a; i >= 2; --i) {
            if (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
            } 
            else {
               continue;
            }
        }
    } 
    else if (a > b || a * b != 0) {
        for (int i = 2; i <= b; ++i) {
            if (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
                break;
            } 
            else {
                break;
            }
        }
        for (int i = b; i >= 2; --i) {
            if (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
            } 
            else {
                continue;
            }
        }
    }
    if (a == b ) {
        cout << a << endl;
    } 
    else if (b == 1) { 
        cout << a << endl;
    } 
    else {
        cout<< a << "/" << b << endl;
    }
    return 0;
}

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    if(a>b){
        if(b>c){
            trigonometric(c,a);
        }
        else if(a>=c){
            trigonometric(b,a);
        }
        else if(c>a){
            trigonometric(b,c);
        }
    }
    else if(a<=b){
        if(c>=b){
            trigonometric(a,c);
        }
        else if(a>=c){
            trigonometric(c,b);
        }
        else if(c>a){
            trigonometric(a,b);
        }
    }
    return 0;
}