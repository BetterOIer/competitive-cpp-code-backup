#include<bits/stdc++.h>
using namespace std;

#define gpr(x) cout<<"Case #"<<x<<": "
#define nl "\n"
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define deb(x) cout<<#x<<"="<<x<<endl
#define pb push_back
#define mp make_pair
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define PI 3.1415926535897932384626433832795
#define fo(i,n) for(i=0;i<n;i++)
#define fop(i,x,n) for(i=x;i<=n;i++)
#define forv(i,l,n) for(i=l;i>=n;i--)
#define uniq(v) v.resize(distance(v.begin(),unique(all(v))))
#define max_map(m) max_element(m.begin(), m.end(), [](auto &x,auto &y) {return x.second<y.second;});
typedef unordered_set<int> usi;
typedef unordered_set<ll> usl;
typedef unordered_set <string> uss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pl;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<string> vs;

const int mod = 1e9+7;
const int N = 3e5;

ll p5(ll n){
    ll cnt=0;
    while(n%5==0){
        n/=5;
        cnt++;
    }
    return cnt;
}

ll p2(ll n){
    ll cnt=0;
    while(n%2==0){
        n/=2;
        cnt++;
    }
    return cnt;
}

void solve(){
    ll i,n,y,x;
    cin>>n;
    fo(i,n){ 
        cin>>y;
        x=p5(y)-p2(y);
        if(x<0) x=0;
        else if(x&1!=0) x++;
        // deb(x);
        y*=(1LL<<x);
        cout<<y<<nl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t=1;
    // cin>>t;
    fo(i,t){
        solve();
    }
    return 0;
}
