#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF=1e18;
int check(const vector<ll> &d,ll B,ll Y){
	ll tmp=0;
	for (auto x:d){
		if (tmp>(INF-x)/B) return 1;
		tmp=tmp*B+x;
	}
	if (tmp<Y) return -1;
	else if (tmp==Y) return 0;
	else return 1;
}

int main(){
	freopen("numgameEX.in","r",stdin);
	freopen("numgameEX.out","w",stdout);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (;T--;){
		ll Y,L;
		cin >> Y >> L;
		ll ans=10;
		//small
		for (ll B=11;B<=40000;B++){
			vector<ll> d;
			int flag=1;
			for (ll tmp=Y;tmp;tmp/=B){
				ll now=tmp%B;
				if (now>=10) flag=0;
				d.push_back(now);
			}
			if (!flag) continue;
			ll y=0;
			for (int i=(int)d.size()-1;i>=0;i--) y=y*10+d[i];
			if (y>=L) ans=max(ans,B);
		}
		//big
		for (ll y=L;y<=10000;y++){
			vector<ll> d;
			for (ll tmp=y;tmp;tmp/=10) d.push_back(tmp%10);
			reverse(d.begin(),d.end());
			ll Bl=10,Br=1e18;
			for (;Bl<Br;){
				ll Bmid=(Bl+Br)/2;
				if (check(d,Bmid,Y)==-1) Bl=Bmid+1;
				else Br=Bmid;
			}
			if (check(d,Bl,Y)==0) ans=max(ans,Bl);
		}
		cout << ans << "\n";
	}
	return 0;
}
