#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> s >> n;
    for (int w = 1; w <= n; w++)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if(i==s.length() - 1){
                s.erase(i,1);
                break;
            }
            if (s[i] > s[i + 1])
            {
                s.erase(i,1);
                break;
            }
            while(s[0]=='0'){
                s.erase(0,1);
            }
        }
        while(s[0]=='0'){
            s.erase(0,1);
        }
    }
    if(s=="")cout<<0;
    cout<<s;
    return 0;
}