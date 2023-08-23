#ifndef STOCK00_H_
#define STOCK00_H_

#include<string>
class Stock{
    private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot(){
        total_val = shares*share_val;
    }
    public:
    void acquire(const std::string & co, int n, double pr);
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show();
};

#endif