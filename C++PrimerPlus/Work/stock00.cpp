#include<iostream>
#include"stock00.h"

void Stock::acquire(const std::string & co, int n, double pr){
    company  = co;
    if(n<0){
        std::cout<<"NOSCBN"<<company<<" set to be 0";
        shares=0;
    }
    else shares = n;
    shares
}