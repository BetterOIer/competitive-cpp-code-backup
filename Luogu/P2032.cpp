#include<iostream>
#include<queue>
using namespace std;
deque <int> Q;
int a[2000005];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (Q.size() && Q.front() < i - k + 1) Q.pop_front();
        while (Q.size() && a[Q.back()] < a[i]) Q.pop_back();
        Q.push_back(i);
        if (i >= k) printf("%d\n",a[Q.front()]);
    }
}