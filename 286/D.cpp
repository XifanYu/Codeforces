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

#define MP make_pair
#define FS first
#define SC second
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#define lc p*2+1
#define rc p*2+2

typedef long long ll;
typedef pair<int,int> pi;

const int Maxn=1e5+5;
const int INF=1<<30;

int T=0;

class wall{
	public:
		int l,r,t;
		bool operator<(const wall &o)const{
			return t<o.t;
		}
};

int n,m;
wall w[Maxn];
set<pi> ss;
int a[Maxn<<1],b[Maxn<<1];
int cnt=0;
int q[Maxn];
ll ans[Maxn];

void make(pi p,int t){
	a[++cnt]=t-p.SC;
	b[cnt]=t-p.FS;
}

void insert(int i){
	set<pi>::iterator it=ss.UB(pi(w[i].l,w[i].r)),tp;
	it--;
	while(it!=ss.end()){
		if(it->FS>=w[i].r){
			break;
		}
		if(it->SC<=w[i].l){
			it++;
			continue;
		}
		if(it->FS<w[i].l){
			pi p1=pi(it->FS,w[i].l),p2=pi(w[i].l,it->SC);
			ss.erase(it);
			ss.insert(p1);
			it=ss.insert(p2).FS;
			continue;
		}
		if(it->SC>w[i].r){
			pi p1=pi(it->FS,w[i].r),p2=pi(w[i].r,it->SC);
			ss.erase(it);
			it=ss.insert(p1).FS;
			ss.insert(p2);
			continue;
		}
		tp=it++;
		make(*tp,w[i].t);
		ss.erase(tp);
	}
}


int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&w[i].l,&w[i].r,&w[i].t);
	}
	sort(w+1,w+m+1);
	ss.insert(pi(-1,INF));
	for(int i=1;i<=m;i++){
		insert(i);
	}
	sort(a+1,a+cnt+1);
	sort(b+1,b+cnt+1);
	for(int i=1;i<=n;i++){
		scanf("%d",q+i);
	}
	int id1=1,id2=1;
	a[cnt+1]=INF;
	b[cnt+1]=INF;
	ll sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		while(a[id1]<q[i]) {
			sum1+=a[id1];
			id1++;
		}
		while(b[id2]<q[i]) {
			sum2+=b[id2];
			id2++;
		}
		ans[i]=((ll)id1*q[i]-sum1)-((ll)id2*q[i]-sum2);
	}
	for(int i=1;i<=n;i++) printf("%I64d\n",ans[i]);
return 0;
}
