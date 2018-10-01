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
const int INF=1e9+5;

class seg{
	public:
		int h,l,r;
		bool operator<(const seg &o) const{
			return h<o.h;
		}
};

seg p[Maxn];

class proj{
	public:
		int l,r,id; 
		bool operator<(const proj &o) const{
			return l<o.l||(l==o.l&&r<o.r);
		}
};

set<proj> ss;
vector<pi> adj[Maxn];
int n,t,h,l,r;
int dp[Maxn];

bool check(int id1,int id2,int w){
	return min(p[id1].r,p[id2].r)-max(p[id1].l,p[id2].l)==w;
}

void insert(proj o){
	set<proj>::iterator it1=ss.LB(o),it2=it1,tp;
	if(it2!=ss.begin()){
		it2--;
		if(it2->r>o.l){
			int w=min(it2->r,o.r)-max(it2->l,o.l);
			if(check(o.id,it2->id,w))adj[o.id].PB(pi(it2->id,w));
			if(it2->l<o.l) ss.insert(proj{it2->l,o.l,it2->id});
			if(it2->r>o.r) ss.insert(proj{o.r,it2->r,it2->id});
			ss.erase(it2);
		}
	}
	while(it1!=ss.end()&&it1->l<o.r){
		int w=min(it1->r,o.r)-max(it1->l,o.l);
		if(check(o.id,it1->id,w))adj[o.id].PB(pi(it1->id,w));
		if(it1->l<o.l) ss.insert(proj{it1->l,o.l,it1->id});
		if(it1->r>o.r) ss.insert(proj{o.r,it1->r,it1->id});
		tp=it1++;
		ss.erase(tp);
	}
	ss.insert(o);
}

void build(){
	for(int i=0;i<=n+1;i++){
		insert(proj{p[i].l,p[i].r,i});
	}
}

int main(){
	scanf("%d%d",&n,&t);
	p[0]=seg{0,-INF,INF};
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&h,&l,&r);
		p[i]=seg{h,l,r};
	}
	p[n+1]=seg{t,-INF,INF};
	sort(p,p+n+2);
	build();
	dp[0]=INF<<1;
	for(int i=1;i<=n+1;i++){
		for(auto v:adj[i]){
			dp[i]=max(dp[i],min(dp[v.FS],v.SC));
		}
	}
	printf("%d\n",dp[n+1]);
return 0;
}
