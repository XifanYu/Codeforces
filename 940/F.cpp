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
#define PB push_back
#define lc p*2+1
#define rc p*2+2

typedef long long ll;
typedef pair<int,int> pi; 

const int Maxn=1e5+5;
const int d=4000;

class que{
	public:
		int l,r,x,id; //left, right, number of modifications, and id
		bool operator<(const que &o)const{
			return (l/d<o.l/d)||(l/d==o.l/d&&(r/d<o.r/d||(r/d==o.r/d&&x<o.x)));
		}
};

class mod{
	public:
		int pos,val; //position and the new value
};

que q[Maxn]; //query
mod m[Maxn],rm[Maxn]; //modification and reverse modification

int n,qs;
int Q=0,M=0;
int t,b,c;
int a[Maxn];

int l=1,r=1,x=0;
set<int> ss; //distinct values among the original and modified arrays
unordered_map<int,int> mp; //the value after coordinate compression
int cnt[Maxn<<1],sz[Maxn]; //count of a number, and the size of a certain count
int ans[Maxn];

void add(int p){
	sz[cnt[a[p]]]--;
	cnt[a[p]]++;
	sz[cnt[a[p]]]++;
}

void del(int p){
	sz[cnt[a[p]]]--;
	cnt[a[p]]--;
	sz[cnt[a[p]]]++;
}

void xadd(int p){
	if(l<=m[p].pos&&m[p].pos<=r){
		sz[cnt[a[m[p].pos]]]--;
		cnt[a[m[p].pos]]--;
		sz[cnt[a[m[p].pos]]]++;
		sz[cnt[m[p].val]]--;
		cnt[m[p].val]++;
		sz[cnt[m[p].val]]++;
	}
	a[m[p].pos]=m[p].val;
}

void xdel(int p){
	if(l<=rm[p].pos&&rm[p].pos<=r){
		sz[cnt[a[rm[p].pos]]]--;
		cnt[a[rm[p].pos]]--;
		sz[cnt[a[rm[p].pos]]]++;
		sz[cnt[rm[p].val]]--;
		cnt[rm[p].val]++;
		sz[cnt[rm[p].val]]++;
	}
	a[rm[p].pos]=rm[p].val;
}

int calc(){
	int rez=1;
	while(sz[rez]) rez++;
	return rez;
}

int main(){
	scanf("%d%d",&n,&qs);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=qs;i++){
		scanf("%d%d%d",&t,&b,&c);
		if(t==1){
			q[Q]={b,c,M,Q};
			Q++;
		}
		else{
			m[M]={b,c};
			M++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!mp[a[i]]){
			mp[a[i]]=1;
			ss.insert(a[i]);
		}
	}
	for(int i=0;i<M;i++){
		if(!mp[m[i].val]){
			mp[m[i].val]=1;
			ss.insert(m[i].val);
		}
	}
	int rk=1;
	for(auto v:ss){
		mp[v]=rk++;
	}
	for(int i=1;i<=n;i++){
		a[i]=mp[a[i]];
	}
	for(int i=0;i<M;i++){
		m[i].val=mp[m[i].val];
	}
	for(int i=0;i<M;i++){
		rm[i].pos=m[i].pos;
		rm[i].val=a[m[i].pos];
		a[m[i].pos]=m[i].val;
	}
	for(int i=M-1;i>=0;i--){
		a[rm[i].pos]=rm[i].val;
	}
	sort(q,q+Q);
	cnt[a[1]]++;
	sz[1]++;
	for(int i=0;i<Q;i++){
		while(x>q[i].x) xdel(--x);
		while(x<q[i].x) xadd(x++);
		while(l>q[i].l) add(--l);
		while(r<q[i].r) add(++r);
		while(l<q[i].l) del(l++);
		while(r>q[i].r) del(r--);
		ans[q[i].id]=calc();
	}
	for(int i=0;i<Q;i++) printf("%d\n",ans[i]);
return 0;
}
