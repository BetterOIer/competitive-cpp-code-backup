#include<iostream>
using namespace std;
int xh[401];
bool jq_act[21];
struct gx{
    int jqh;
    int ti;
};
struct gj{
    int si=0;
    gx a[21];
}gj[21];
int main(){
    int m,n,ti_to,ti_to_min = INT32_MAX;
    cin>>m>>n;
    const int t = m*n;
    for(int i = 1;i<=t;i++){
        cin>>xh[i];
    }
    for(int i =1;i<=3;i++){
        for(int w =1;w<=3;w++){
            cin>>gj[i].a[w].jqh;
        }
    }
    for(int i =1;i<=3;i++){
        for(int w =1;w<=3;w++){
            cin>>gj[i].a[w].ti;
        }
    }
    for(int i = 1;i<=t;i++){
        gj[xh[i]].si++;
        jq_act[gj[xh[i]].a[gj[xh[i]].si].jqh] = true;
        //ti_to+=gj[xh[i]].a[gj[xh[i]].si].ti;
        if(jq_act[gj[xh[i+1]].a[gj[xh[i+1]].si+1].jqh]==false){
            
        }
    }
    return 0;
} 