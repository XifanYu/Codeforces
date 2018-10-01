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
const ll INF=1e15+5;

int n,m,x,y,MN=1;
int a[Maxn],s[Maxn];

class line{
	public:
		ll k,b;
		bool operator<(const line &o)const{
			return k<o.k||(k==o.k&&b<o.b);
		}
		bool operator==(const line &o)const{
			return k==o.k&&b==o.b;
		}
};

set<line> hull[Maxn<<2];

bool check(line l1,line l2,line l3){
	double d=1.0*(l3.k-l1.k)*(l2.b-l1.b)-1.0*(l2.k-l1.k)*(l3.b-l1.b);
	if(d>=0) return true;
	return false;
}

void insert(line o,int id){
	if(hull[id].size()<2){
		hull[id].insert(o);
		return;
	}
	set<line>::iterator r=hull[id].LB(o),l=r,t;
	if(l!=hull[id].end()&&o==*l) return;
	if(l!=hull[id].begin()){
		l--;
		if(r!=hull[id].end()&&check(*l,o,*r)) return;
		hull[id].insert(o);
		while(l!=hull[id].begin()){
			t=l--;
			if(check(*l,*t,o)){
				hull[id].erase(t);
			}
			else break;
		}
	}
	if(r!=hull[id].end()){
		t=r++;
		while(r!=hull[id].end()){
			if(check(o,*t,*r)){
				hull[id].erase(t);
				t=r++;
			}
			else break;
		}
	}
}

void build(){
	while(MN<n) MN*=2;
	for(int p=2*MN-2;p>=0;p--){
		insert(line{-10005,INF},p);
		insert(line{10005,INF},p);
	}
	for(int p=n;p>0;p--){
		insert(line{a[p],p*a[p]-s[p]},p+MN-2);
	}
	for(int p=MN-2;p>=0;p--){
		for(auto v:hull[lc]) insert(v,p);
		for(auto v:hull[rc]) insert(v,p);
	}
}

ll val(line o,int x,int y){
	return (ll)(x-y)*o.k+o.b;
}
ll calc(int id,int x,int y){
	int ub=10001,lb=-10001,mi;
	set<line>::iterator it;
	while(ub-lb>1){
		mi=(ub+lb)>>1;
		it=hull[id].LB(line{mi,INF});
		if(it!=hull[id].begin()&&val(*it,x,y)>val(*prev(it),x,y)) ub=mi;
		else lb=mi;
	}
	it=hull[id].LB(line{lb,INF});
	return val(*it,x,y)+s[y]; 
}

ll query(int x,int y,int l,int r,int p=0,int l1=1,int r1=MN){
	if(l<=l1&&r>=r1) return calc(p,x,y);
	if(l>r1||r<l1) return INF;
	return min(query(x,y,l,r,lc,l1,(l1+r1)>>1),query(x,y,l,r,rc,(l1+r1+1)>>1,r1));
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	build();
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		printf("%I64d\n",query(x,y,y-x+1,y));
	}
return 0;
}
