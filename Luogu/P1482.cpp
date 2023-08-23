#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    string s;
    int a,b,c,d,son,father;
    cin>>s;
    sscanf(s.c_str(),"%d/%d",&a,&b);
    cin>>s;
    sscanf(s.c_str(),"%d/%d",&c,&d);
    son=a*c,father=b*d;
    int minn=son<father? son:father;
    while(true){
        next:
        for(int i = 2;i<=minn;i++){
            if(son%i==0&&father%i==0){
                son/=i;
                father/=i;
                minn=son<father? son:father;
                goto next;
            }
        }
        break;
    }
    cout<<father<<" "<<son;
    return 0;
}