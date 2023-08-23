#include<iostream>
#include<vector>
using namespace std;
struct ship{
    int t;
    vector <int> coutry;
};
vector <ship> Q;
vector <int> P;
int main(){
    int n;
    cin>>n;
    Q.resize(n);
    for(int i = 0;i<=n-1;i++){
        int k;
        cin>>Q[i].t>>k;
        Q[i].coutry.resize(k);
        for(int w = 0;w<=k-1;w++){
            cin>>Q[i].coutry[w];
        }
        //P.resize(0);
        for(int w = 0;w<=i;w++){
            if(Q[i].t-Q[w].t<86400){
                for(int s = 0;s<=Q[w].coutry.size()-1;s++){
                    int flag=0;
                    for(int j = 0;j<P.size()-1;j++){
                        if(P[j]==Q[w].coutry[s]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        P.push_back(Q[w].coutry[s]);
                    }
                }
            }
        }
        cout<<P.size();
    }
    return 0;
}
