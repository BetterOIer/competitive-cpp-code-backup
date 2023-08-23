#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int f1[10000], f2[10000], f3[20000], f4[20000];
struct minister
{
    int L;
    int R;
} a[1000/* 10 */];
bool comp(minister a, minister b)
{
    return a.L * a.R < b.L * b.R;
}
int conversion(long long a, int po)
{
    /* 将数的各个数位存到数组po */
    int n = -1;
    while (a != 0)
    {
        if (po == 1)
            f1[++n] = a % 10;
        else
            f2[++n] = a % 10;
        a /= 10;
    }
    return n + 1; //返回的是数据长度，无0
}
int HighAccuracyMul(int len1, int len2)
{
    int len = max(len1, len2);
    int i,w;
    for (i = 0; i <= len1 - 1; i++)
    {
        for (w = 0; w <= len2 - 1; w++)
        {
            f3[i + w] += f1[i] * f2[w];
            f3[i + w +1] += f3[i+w] / 10;
            f3[i] %= 10;
        }
    }
    int k = i+w+1;
    if(f3[k]==0){
        return k-1;
    }
    if(f3[k]>0&&f3[k]<10){
        return k;
    }
    while(f3[k]>10){
        f3[k+1] += f3[k] / 10;
        f3[k] %= 10;
        k++;
    }
    return k;
}
int HighLowDivision(int len, int b)
{
    int c = 0;
    bool flag = false;
    for (int i = 0; i <= len - 1; i++)
    {
        c = c * 10 + f1[i];
        f3[i] = c / b;
        if(f3[i]){
            flag = true;
        }
        c = c % b;
    }
    if(!flag){
        return 1;
    }
    while(f3[0]==0){
        for(int i = 0;i<=len-1;i++){
            f3[i] = f3[i+1];
        }
        --len;
    }
    return len;
}
void trans_3_to_1(int k)
{
    /* 将数组f3换到f1, 并清空f2,f3*/
    memset(f1, 0, sizeof(f1));
    for (int i = 0; i <= k - 1; i++)
    {
        f1[i] = f3[i];
    }
    memset(f3, 0, sizeof(f3));
    memset(f2, 0, sizeof(f2));
}
void trans_3_to_4(int k)
{
    /* 将数组f3换到f4, 并清空f3*/
    memset(f4, 0, sizeof(f4));
    for (int i = 0; i <= k - 1; i++)
    {
        f4[i] = f3[i];
    }
    memset(f3, 0, sizeof(f3));
}
void head_tail_trans_1(int len)
{
    for (int i = 0; i < (len) / 2; i++)
    {
        int k = f1[i];
        f1[i] = f1[len - 1 - i];
        f1[len - 1 - i] = k;
    }
}
void head_tail_trans_3(int len)
{
    for (int i = 0; i < (len) / 2; i++)
    {
        int k = f3[i];
        f3[i] = f3[len - 1 - i];
        f3[len - 1 - i] = k;
    }
}
int compare(int len1, int len2)//正序
{
    if (len1 < len2)
    {
        memset(f3, 0, sizeof(f3));
        return len2;
    }
    else if (len1 > len2)
    {
        trans_3_to_4(len1);
        return len1;
    }
    else
    {
        for (int i = 0; i <= len1-1; i++)
        {
            if (f3[i] == f4[i])
            {
                continue;
            }
            else if (f3[i] > f4[i])
            {
                trans_3_to_4(len1);
                return len1;
            }
            else
            {
                memset(f3, 0, sizeof(f3));
                return len2;
            }
        }
        memset(f3, 0, sizeof(f3));
        return len1;
    }
}
int main()
{
     freopen("P1080_9.in","r",stdin);
    // freopen("P.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i].L >> a[i].R;
    }
    sort(a + 1, a + n + 1, comp);
    int k = conversion(a[0].L, 1), k1, k2 = 0;
    head_tail_trans_1(k);
    k1 = HighLowDivision(k, a[1].R);
    k2 = compare(k1, k2);
    for (int i = 1; i <= n-1; i++)
    {
        head_tail_trans_1(k);
        k = HighAccuracyMul(k, conversion(a[i].L, 2));
        head_tail_trans_3(k);//正序
        trans_3_to_1(k);
        k1 = HighLowDivision(k, a[i+1].R);
        k2 = compare(k1, k2);
    }
    for (int i = 0; i <= k2 - 1; i++)
    {
        cout << f4[i];
    }
     fclose(stdin);
    // fclose(stdout);
    return 0;
}