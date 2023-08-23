#include<iostream>
using namespace std;
void deal(string zhong,string hou){
    cout<<hou[hou.length()-1];
    int po=zhong.find(hou[hou.length()-1]);
    if(po!=0){
        string zhong1=zhong.substr(0,po);
        string hou1=hou.substr(0,po);
        deal(zhong1,hou1);
    }
    if(zhong.length()-po-1!=0){
        string zhong2=zhong.substr(po+1,zhong.length()-po-1);
        string hou2=hou.substr(po,zhong.length()-po-1);
        deal(zhong2,hou2);
    }
}
int main(){
    string zhong,hou;
    cin>>zhong>>hou;
    deal(zhong,hou);
}