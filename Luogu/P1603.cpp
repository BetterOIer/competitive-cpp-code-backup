#include <iostream>
#include <string>
using namespace std;
int pd(string s)
{
    int i;
    s[0] = tolower(s[0]);
    if(s == "zero"||s == "no"){
        i=0;
    }else if (s == "one" || s == "a" || s == "another" || s == "first")
    {
        i = 1;
    }
    else if (s == "two" || s == "second" || s == "both")
    {
        i = 2;
    }
    else if (s == "three" || s == "thrid")
    {
        i = 3;
    }
    else if (s == "four")
    {
        i = 4;
    }
    else if (s == "five")
    {
        i = 5;
    }
    else if (s == "six")
    {
        i = 6;
    }
    else if (s == "seven")
    {
        i = 7;
    }
    else if (s == "eight")
    {
        i = 8;
    }
    else if (s == "nine")
    {
        i = 9;
    }
    else if (s == "ten")
    {
        i = 10;
    }
    else if (s == "eleven")
    {
        i = 11;
    }
    else if (s == "twelve")
    {
        i = 12;
    }
    else if (s == "thirteen")
    {
        i = 13;
    }
    else if (s == "fourteen")
    {
        i = 14;
    }
    else if (s == "fifteen")
    {
        i = 15;
    }
    else if (s == "sixteen")
    {
        i = 16;
    }
    else if (s == "seventeen")
    {
        i = 17;
    }
    else if (s == "eighteen")
    {
        i = 18;
    }
    else if (s == "nineteen")
    {
        i = 19;
    }
    else if (s == "tewnty")
    {
        i = 20;
    }
    else
    {
        i = 21;
    }
    return i;
}
int main()
{
    long long summin = 999999999999, sum = 0;
    int loc1, a;
    string s, s2;
    char b, c;
    getline(cin, s);
    s[s.length() - 1] = ' ';
    loc1 = 0;
    while (s.find(" ") != -1)
    {
        string s1 = s.substr(loc1, s.find(" "));
        s = s.substr(s.find(" ") + 1, s.length() - 1);
        a = pd(s1);
        if (a==21)
        {
            continue;
        }
        a = a * a % 100;
        if (a < 10 && a != 0)
        {
            b = '0' + a;
            s2 = s2 + "0" + b;
        }
        if (a == 0)
        {
            s2 =s2 + "00";
        }
        else if (a >= 10)
        {
            b = a % 10 + '0';
            c = (a - a % 10) / 10 + '0';
            s2 = s2+c + b;
        }
    }
    s2 = s2+s2;
    for (int i = 0; i <= s2.length()/2-1;i+=2){
        string s3 = s2.substr(i,s2.length()/2);
        for (int w = 0; w <= s3.length() - 1; ++w){
            sum= sum*10+(s3[w]-'0');
        }
        summin = sum < summin ? sum : summin;
        sum=0;
    }
    cout << summin;
    return 0;
}