#include<iostream>
#include<map>
using namespace std;
map <string,int> edu;
int main(){
    int n,opt;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>opt;
        if(opt==1){
            string name;
            int score;
            cin>>name>>score;
            edu[name]=score;
            cout<<"OK"<<endl;
        }else if(opt==2){
            string name;
            cin>>name;
            if(edu.find(name)!=edu.end())cout<<edu[name]<<endl;
            else cout<<"Not found"<<endl;
        }else if(opt==3){
            string name;
            cin>>name;
            if(edu.find(name)!=edu.end()){
                edu.erase(name);
                cout<<"Deleted successfully"<<endl;
            }
            else cout<<"Not found"<<endl;
        }else if(opt==4){
            cout<<edu.size()<<endl;
        }
    }
}