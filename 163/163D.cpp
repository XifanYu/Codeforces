#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <memory.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;

map<ll,int> prime;
map<ll,ll> nextp;
set<ll> divisor;


void gen(ll now,ll prod){
	ll nex=nextp[now];
	if(nex!=0){
		ll j=prod;
		for(int i=0;i<=prime[nex];i++,j*=nex){
			gen(nex,j);
		}
	}
	if(nex==0) {
		divisor.insert(prod);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		divisor.clear();
		prime.clear();
		nextp.clear();
		while(x--){
			ll p;
			int a;
			scanf("%I64d%d",&p,&a);
			prime[p]=a;
		}
		ll pr=-1;
		for(auto prm:prime){
			ll p=prm.first;
			nextp[pr]=p;
			pr=p;
		}
		gen(-1,1);
		ll ans=1e18+5;
		ll v=*(--divisor.end());
		ll s1,s2,s3;
		int lb=1,ub=1e6+1;
		while(ub-lb>1){
			int mi=(ub+lb)>>1;
			if((ll)mi*mi*mi>v) ub=mi;
			else lb=mi;
		}
		auto id1=--upper_bound(divisor.begin(),divisor.end(),(ll)ub);
		for(;;id1--){
			ll d1=*id1;
			if(2*(2*d1*sqrt(v/d1)+v/d1)>=ans) break;
			ll n=v/d1;
			auto id2=--upper_bound(divisor.begin(),divisor.end(),sqrt(n));
			while(n%(*id2)!=0) {
				if(*id2<d1) break;
				id2--;
			}
			ll d2=*id2;
			if(d2<d1) continue;
			ll d3=n/d2;
			if(ans>2*(d1*d2+d2*d3+d3*d1)){
				ans=2*(d1*d2+d2*d3+d3*d1);
				s1=d1,s2=d2,s3=d3;
			}
			if(id1==divisor.begin()) break;
		}
		printf("%I64d %I64d %I64d %I64d\n",ans,s1,s2,s3);
	}
return 0;
} 
