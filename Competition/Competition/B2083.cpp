#include<iostream>
using namespace std;
int main(){
    int a, b, f;
    char c;
    cin>>a>>b>>c>>f;
    if(f){
        for(int i= 1;i<=a;i++){
            for(int w= 1;w<=b;w++){
                cout<<c;
            }
            cout<<endl;
        }
    }
    else{
        for(int i= 1;i<=b;i++){
            cout<<c;
        }
        cout<<endl;
        for(int w= 1;w<=(a-2);w++){
            cout<<c;
            for(int i= 1;i<=(b-2);i++){
                cout<<" ";
            }
            cout<<c<<endl;
        }
        for(int i= 1;i<=b;i++){
            cout<<c;
        }
    }
    return 0;
} 