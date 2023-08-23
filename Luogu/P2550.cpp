#include<iostream>
using namespace std;
int main(){
    int n,sum = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0;
    cin>>n;
    int my_ticket[n+1][8], ri_ticket[8];
    for(int i = 1;i<=7;i++){
        cin>>ri_ticket[i];
    }
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=7;w++){
            cin>>my_ticket[i][w];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=7;w++){
            for(int j = 1;j<=7;j++){
                if(my_ticket[i][w]==ri_ticket[j]){
                    sum++;
                    break;
                }
            }
        }
        if(sum == 7){
            a1++;
            sum = 0;
        }
        else if(sum == 6){
            a2++;
            sum = 0;
        }
        else if(sum == 5){
            a3++;
            sum = 0;
        }
        else if(sum == 4){
            a4++;
            sum = 0;
        }
        else if(sum == 3){
            a5++;
            sum = 0;
        }
        else if(sum == 2){
            a6++;
            sum = 0;
        }
        else if(sum == 1){
            a7++;
            sum = 0;
        }
    }
    cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<a6<<" "<<a7<<" ";
    
    return 0;
} 