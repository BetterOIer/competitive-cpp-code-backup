#include<iostream>
#include<set>
using namespace std;
set <int> wood;
set <int>::iterator l1,l2,l3;
int main(){
    int n,opt,len;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>opt>>len;
        if(opt==1){
            if (!wood.insert(len).second) cout<<"Already Exist"<<endl;
            else wood.insert(len);
        }else if(opt==2){
            if(wood.empty())cout<<"Empty"<<endl;
            else if(wood.find(len)!=wood.end()){
                cout<<len<<endl;
                wood.erase(wood.find(len));
            }
            else{
                l1 = l2 = l3 = wood.lower_bound(len);
				if (l1 == wood.begin()) cout << *l1, wood.erase(l1);
				else if (l1 == wood.end()) cout << *(-- l3), wood.erase(l3);
				else if (*l1 - len < len - *(-- l2)) cout << *(l3), wood.erase(l3);
				else cout << *(-- l3), wood.erase(l3);
                cout<<endl;
            }
        }
    }
}