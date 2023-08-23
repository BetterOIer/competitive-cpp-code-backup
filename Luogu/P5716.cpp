#include <iostream>
using namespace std;
int main(){
    int y, m, x;
    cin>>y>>m;
    if (y%100==0){
		if(y%400==0){
			x = 1;
		} 
		else{
			x = 0;
		}
	}
	else{
		if(y%4==0){
			x = 1;
		}
		else{
			x = 0;
		}
	}
    if(x == 1&&m ==2){
        cout<<29;
    } 
    else if(x ==0&&m ==2){
        cout<<28;
    }
    else if(m == 1||m == 3||m == 5||m == 7||m == 8||m == 10||m == 12){
        cout<<31;
    }
    else if(m == 4||m == 6||m == 9||m == 11){
        cout<<30;
    }

    return 0;
}